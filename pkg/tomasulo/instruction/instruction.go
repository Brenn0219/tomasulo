package instruction

import "ts/pkg/tomasulo/registrar"

type InstructionType uint8

const (
	ADD InstructionType = iota
	SUB
	MULT
	DIV
	LDR
	STD
)

type Instruction struct {
	Id      uint
	Type    InstructionType
	Destiny registrar.Registrar
	Op1     registrar.Registrar
	Op2     registrar.Registrar
}
