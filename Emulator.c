#include "Registers.h"
#include "Ram.h"
#include "Opcodes.h"
#include "CounterStep.h"

int main()
{
	ZeroRegisters();
	ZeroRam();

	for (;;)
	{
		int opcost = CounterStep[_RAM[_RPC]];
		switch (_RAM[_RPC])
		{

		case OP_LD_A_A: _RA_A = _RA_A; break;
		case OP_LD_B_A: _RA_A = _RB_A; break;
		case OP_LD_C_A: _RA_A = _RC_A; break;
		case OP_LD_D_A: _RA_A = _RD_A; break;
		case OP_LD_E_A: _RA_A = _RE_A; break;
		case OP_LD_H_A: _RA_A = _RH_A; break;
		case OP_LD_L_A: _RA_A = _RL_A; break;

		case OP_LD_A_B: _RB_A = _RA_A; break;
		case OP_LD_B_B: _RB_A = _RB_A; break;
		case OP_LD_C_B: _RB_A = _RC_A; break;
		case OP_LD_D_B: _RB_A = _RD_A; break;
		case OP_LD_E_B: _RB_A = _RE_A; break;
		case OP_LD_H_B: _RB_A = _RH_A; break;
		case OP_LD_L_B: _RB_A = _RL_A; break;

		case OP_LD_A_C: _RC_A = _RA_A; break;
		case OP_LD_B_C: _RC_A = _RB_A; break;
		case OP_LD_C_C: _RC_A = _RC_A; break;
		case OP_LD_D_C: _RC_A = _RD_A; break;
		case OP_LD_E_C: _RC_A = _RE_A; break;
		case OP_LD_H_C: _RC_A = _RH_A; break;
		case OP_LD_L_C: _RC_A = _RL_A; break;

		case OP_LD_A_D: _RD_A = _RA_A; break;
		case OP_LD_B_D: _RD_A = _RB_A; break;
		case OP_LD_C_D: _RD_A = _RC_A; break;
		case OP_LD_D_D: _RD_A = _RD_A; break;
		case OP_LD_E_D: _RD_A = _RE_A; break;
		case OP_LD_H_D: _RD_A = _RH_A; break;
		case OP_LD_L_D: _RD_A = _RL_A; break;

		case OP_LD_A_E: _RE_A = _RA_A; break;
		case OP_LD_B_E: _RE_A = _RB_A; break;
		case OP_LD_C_E: _RE_A = _RC_A; break;
		case OP_LD_D_E: _RE_A = _RD_A; break;
		case OP_LD_E_E: _RE_A = _RE_A; break;
		case OP_LD_H_E: _RE_A = _RH_A; break;
		case OP_LD_L_E: _RE_A = _RL_A; break;

		case OP_LD_A_H: _RH_A = _RA_A; break;
		case OP_LD_B_H: _RH_A = _RB_A; break;
		case OP_LD_C_H: _RH_A = _RC_A; break;
		case OP_LD_D_H: _RH_A = _RD_A; break;
		case OP_LD_E_H: _RH_A = _RE_A; break;
		case OP_LD_H_H: _RH_A = _RH_A; break;
		case OP_LD_L_H: _RH_A = _RL_A; break;

		case OP_LD_A_L: _RL_A = _RA_A; break;
		case OP_LD_B_L: _RL_A = _RB_A; break;
		case OP_LD_C_L: _RL_A = _RC_A; break;
		case OP_LD_D_L: _RL_A = _RD_A; break;
		case OP_LD_E_L: _RL_A = _RE_A; break;
		case OP_LD_H_L: _RL_A = _RH_A; break;
		case OP_LD_L_L: _RL_A = _RL_A; break;

		case OP_LD_N_A: _RA_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_B: _RB_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_C: _RC_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_D: _RD_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_E: _RE_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_H: _RH_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_L: _RL_A = _RAM[_RPC + 1]; break;

		case OP_LD_HL_A: _RA_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_B: _RB_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_C: _RC_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_D: _RD_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_E: _RE_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_H: _RH_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_L: _RL_A = _RAM[_RH_A << 8 | _RL_A]; break;

		case OP_LD_IXD_R:
		{
							byte n = _RAM[_RPC + 2];
							switch (_RAM[_RPC + 1])
							{
							case OP_LD_HL_A: _RA_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_B: _RB_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_C: _RC_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_D: _RD_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_E: _RE_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_H: _RH_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_L: _RL_A = _RAM[_RIX + n]; break;
							case OP_LD_A_HL: _RAM[_RIX + n] = _RA_A; break;
							case OP_LD_B_HL: _RAM[_RIX + n] = _RB_A; break;
							case OP_LD_C_HL: _RAM[_RIX + n] = _RC_A; break;
							case OP_LD_D_HL: _RAM[_RIX + n] = _RD_A; break;
							case OP_LD_E_HL: _RAM[_RIX + n] = _RE_A; break;
							case OP_LD_H_HL: _RAM[_RIX + n] = _RH_A; break;
							case OP_LD_L_HL: _RAM[_RIX + n] = _RL_A; break;
							case OP_LD_N_HL:
							{
											   _RAM[_RIX + n] = _RAM[_RPC + 3];
											   opcost = 4;
							}
								break;
							}
		}
			break;
		case OP_LD_IYD_R:
		{
							byte n = _RAM[_RPC + 2];
							switch (_RAM[_RPC + 1])
							{
							case OP_LD_HL_A: _RA_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_B: _RB_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_C: _RC_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_D: _RD_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_E: _RE_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_H: _RH_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_L: _RL_A = _RAM[_RIY + n]; break;
							case OP_LD_A_HL: _RAM[_RIY + n] = _RA_A; break;
							case OP_LD_B_HL: _RAM[_RIY + n] = _RB_A; break;
							case OP_LD_C_HL: _RAM[_RIY + n] = _RC_A; break;
							case OP_LD_D_HL: _RAM[_RIY + n] = _RD_A; break;
							case OP_LD_E_HL: _RAM[_RIY + n] = _RE_A; break;
							case OP_LD_H_HL: _RAM[_RIY + n] = _RH_A; break;
							case OP_LD_L_HL: _RAM[_RIY + n] = _RL_A; break;
							case OP_LD_N_HL:
							{
											   _RAM[_RIY + n] = _RAM[_RPC + 3];
											   opcost = 4;
							}
							}
		}
			break;

		case OP_LD_A_HL: _RAM[_RH_A << 8 | _RL_A] = _RA_A; break;
		case OP_LD_B_HL: _RAM[_RH_A << 8 | _RL_A] = _RB_A; break;
		case OP_LD_C_HL: _RAM[_RH_A << 8 | _RL_A] = _RC_A; break;
		case OP_LD_D_HL: _RAM[_RH_A << 8 | _RL_A] = _RD_A; break;
		case OP_LD_E_HL: _RAM[_RH_A << 8 | _RL_A] = _RE_A; break;
		case OP_LD_H_HL: _RAM[_RH_A << 8 | _RL_A] = _RH_A; break;
		case OP_LD_L_HL: _RAM[_RH_A << 8 | _RL_A] = _RL_A; break;

		case OP_LD_N_HL: _RAM[_RH_A << 8 | _RL_A] = _RAM[_RPC + 1]; break;
		case OP_LD_BC_A: _RA_A = _RAM[_RB_A << 8 | _RC_A]; break;
		case OP_LD_DE_A: _RA_A = _RAM[_RD_A << 8 | _RE_A]; break;
		case OP_LD_NN_A: _RA_A = _RAM[_RAM[_RPC + 2] << 8 | _RAM[_RPC + 1]];
		case OP_LD_A_BC: _RAM[_RB_A << 8 | _RC_A] = _RA_A; break;
		case OP_LD_A_DE: _RAM[_RD_A << 8 | _RE_A] = _RA_A; break;
		case OP_LD_A_NN: _RAM[_RAM[_RPC + 2] << 8 | _RAM[_RPC + 1]] = _RA_A; break;
		case OP_LD_I_A: 

		}

		_RPC += opcost;

	}


	return 0;
}
