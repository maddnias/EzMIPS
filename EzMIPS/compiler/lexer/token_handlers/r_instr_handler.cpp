#include "r_instr_handler.h"
#include "..\tokens\r_instr_tok.h"


r_instr_handler::r_instr_handler()
{
}


r_instr_handler::~r_instr_handler(void)
{
}

mips_token_ptr r_instr_handler::parse_token(parser_ctx &ctx){
		bool successFlag = true;
		
		int curCol = ctx.get_src_reader()->get_current_col();
		int firstChar = ctx.get_src_reader()->peek();

		r_instr_tok *tok = NULL;

		switch(firstChar) {
		case 'a':
			if(ctx.get_src_reader()->matches_unique(L"add")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"add");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"addu")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"addu");
				ctx.get_src_reader()->advance(4);

			} else if(ctx.get_src_reader()->matches_unique(L"and")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"and");
				ctx.get_src_reader()->advance(3);

			} else {
				successFlag = false;
			}
			break;
		case 'd':
			if(ctx.get_src_reader()->matches_unique(L"div")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"div");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"divu")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"divu");
				ctx.get_src_reader()->advance(4);

			} else {
				successFlag = false;
			}
			break;
		case 'j':
			if(ctx.get_src_reader()->matches_unique(L"jr")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"jr");
				ctx.get_src_reader()->advance(2);

			} else {
				successFlag = false;
			}
			break;
		case 'm':
			if(ctx.get_src_reader()->matches_unique(L"mfhi")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"mfhi");
				ctx.get_src_reader()->advance(4);

			} else if(ctx.get_src_reader()->matches_unique(L"mflo")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"mflo");
				ctx.get_src_reader()->advance(4);

			} else if(ctx.get_src_reader()->matches_unique(L"mfc0")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col()); // special
				tok->set_raw_tok(L"mfc0");
				ctx.get_src_reader()->advance(4);

			} else if(ctx.get_src_reader()->matches_unique(L"mult")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"mult");
				ctx.get_src_reader()->advance(4);

			} else if(ctx.get_src_reader()->matches_unique(L"multu")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"multu");
				ctx.get_src_reader()->advance(5);

			} else {
				successFlag = false;
			}
			break;
		case 'n':
			if(ctx.get_src_reader()->matches_unique(L"nor")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"nor");
				ctx.get_src_reader()->advance(3);

			} else {
				successFlag = false;
			}
			break;
		case 'x':
			if(ctx.get_src_reader()->matches_unique(L"xor")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"xor");
				ctx.get_src_reader()->advance(3);

			} else {
				successFlag = false;
			}
			break;
		case 'o':
			if(ctx.get_src_reader()->matches_unique(L"or")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"or");
				ctx.get_src_reader()->advance(2);

			} else {
				successFlag = false;
			}
			break;
		case 's':
			if(ctx.get_src_reader()->matches_unique(L"slt")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"slt");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"sltu")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"sltu");
				ctx.get_src_reader()->advance(4);

			} else if(ctx.get_src_reader()->matches_unique(L"sll")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"sll");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"srl")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"srl");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"sra")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"sra");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"sub")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"sub");
				ctx.get_src_reader()->advance(3);

			} else if(ctx.get_src_reader()->matches_unique(L"subu")){
				tok = new r_instr_tok(INSTRUCTION_R, ctx.get_src_reader()->get_current_row(),
					ctx.get_src_reader()->get_current_col());
				tok->set_raw_tok(L"subu");
				ctx.get_src_reader()->advance(4);
			} else {
				successFlag = false;
			}
			break;

		default:
			successFlag = false;
			break;
		}
		
		successFlag = tok != NULL;
		if(successFlag){
			return mips_token_ptr(tok);
		}

		return NULL;
}
