package buffer

import "tomasulo/pkg/instruction"

type Buffer struct {
	Id   uint
	Busy bool
	instruction.Instruction
	Issue     uint
	Execute   uint
	WriteBack uint
	Commit    uint
}
