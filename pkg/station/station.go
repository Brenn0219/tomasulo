package station

import (
	"tomasulo/pkg/instruction"
	"tomasulo/pkg/registrar"
)

type Station struct {
	Buys          bool
	Op            instruction.InstructionType
	Vj            registrar.Registrar
	Vk            registrar.Registrar
	Qj            uint
	Qk            uint
	InstructionId uint
}

type RegistrarStatus struct {
	registrar.Registrar
	Busy bool
}

type ReservationStations []Station
