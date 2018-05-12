//**********************************************************************************************************************************************************//
//	Plik: C_relation.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_relation.hpp"

C_relation::C_relation() { b_value_ = false; }
C_relation::C_relation(C_id& ID) { id_ = ID; b_value_ = false; }
C_relation::C_relation(C_id& ID, int i_TYP, bool b_active) { id_ = ID; i_typ_ = i_TYP, b_value_ = b_active; }
void operator<<(std::ofstream &is, C_relation &C) {
	is << C.b_value_<<' ';
	is << C.i_typ_<<' ';
	is << C.id_;
	is << ' ';
}
void operator>>(std::ifstream& is, C_relation &C) {
	is >> C.b_value_;
	is >> C.i_typ_;
	is >> C.id_;
}
void C_relation::m_wiew() {}
C_relation::~C_relation() {}
void C_relation::m_active() { b_value_ = true; }
void C_relation::m_deactive() { b_value_ = false; }
void C_relation::m_add_typ(int i_variable) { i_typ_ = i_variable; }
void C_relation::m_get_typ(int& i_variable) { i_variable = i_typ_; }
void C_relation::m_add_id(C_id& ID) { id_ = ID; }
void C_relation::m_get_id(C_id& ID) { ID = id_; }

