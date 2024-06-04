package buffer

import (
	"ts/pkg/tomasulo/instruction"
)

type Buffer struct {
	Id   uint
	Busy bool
	instruction.Instruction
	Issue     uint
	Execute   uint
	WriteBack uint
	Commit    uint
}

type ReorderBuffer []Buffer
