package analyzer

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"ts/pkg/tomasulo/buffer"
	"ts/pkg/tomasulo/instruction"
	"ts/pkg/tomasulo/registrar"
)

func parseRegistrar(str string) (registrar.Registrar, error) {
	if !strings.HasPrefix(str, "R") {
		return registrar.Registrar{}, fmt.Errorf("format registrar invalid")
	}

	id, err := strconv.Atoi(str[1:])
	if err != nil {
		return registrar.Registrar{}, fmt.Errorf("registrar invalid")
	}

	return registrar.Registrar{Id: uint(id), Value: rand.Intn(21)}, nil
}

func parseInstructionType(str string) instruction.InstructionType {
	switch str {
	case "ADD":
		return instruction.ADD
	case "SUB":
		return instruction.SUB
	case "MULT":
		return instruction.MULT
	case "DIV":
		return instruction.DIV
	case "LDR":
		return instruction.LDR
	case "STD":
		return instruction.STD
	default:
		return instruction.InvalidType
	}
}

func parseInstruction(line string, id int) (instruction.Instruction, error) {
	piece := strings.Fields(line)
	if len(piece) < 3 {
		return instruction.Instruction{}, fmt.Errorf("format instruction invalid")
	}

	instructionType := parseInstructionType(piece[0])
	if instructionType == instruction.InvalidType {
		return instruction.Instruction{}, fmt.Errorf("instruction type invalid")
	}

	destiny, err := parseRegistrar(piece[1])
	if err != nil {
		return instruction.Instruction{}, err
	}

	op1, err := parseRegistrar(piece[2])
	if err != nil {
		return instruction.Instruction{}, err
	}

	op2, err := parseRegistrar(piece[3])
	if err != nil {
		return instruction.Instruction{}, err
	}

	return instruction.Instruction{Id: uint(id), Type: instructionType, Destiny: destiny, Op1: op1, Op2: op2}, nil
}

func ReadInstructions(path string) (buffer.ReorderBuffer, error) {
	file, err := os.Open(path)

	if err != nil {
		return buffer.ReorderBuffer{}, fmt.Errorf("file open err: %w", err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	reorderBuffer := make([]buffer.Buffer, 4)
	i := 0

	for scanner.Scan() {
		line := scanner.Text()

		istr, err := parseInstruction(line, i+1)
		if err != nil {
			return buffer.ReorderBuffer{}, fmt.Errorf("error parsing instruction: %w", err)
		}

		reorderBuffer[i].Instruction = istr
		i += 1
	}

	if err := scanner.Err(); err != nil {
		return buffer.ReorderBuffer{}, fmt.Errorf("erro ao ler arquivo: %w", err)
	}

	return reorderBuffer, nil
}
