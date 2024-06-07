package print

import (
	"fmt"
	"ts/pkg/tomasulo/instruction"
)

func printInstructionType(instructionType instruction.InstructionType) string {
	switch instructionType {
	case instruction.ADD:
		return "ADD"
	case instruction.SUB:
		return "SUB"
	case instruction.MULT:
		return "MULT"
	case instruction.DIV:
		return "DIV"
	case instruction.LDR:
		return "LDR"
	case instruction.STD:
		return "STD"
	default:
		return ""
	}
}

func PrintInstruction(inst instruction.Instruction) {
	fmt.Printf("id: %d type: %s destiny: R%d(%d) op1: R%d(%d) op2: R%d(%d)\n", inst.Id, printInstructionType(inst.Type), inst.Destiny.Id, inst.Destiny.Value, inst.Op1.Id, inst.Op1.Value, inst.Op2.Id, inst.Op2.Value)
}
