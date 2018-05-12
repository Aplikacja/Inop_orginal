//**********************************************************************************************************************************************************//
//	Plik: C_relationship.cpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_relationship.hpp"

C_relationship::C_relationship() {}
C_relationship::C_relationship(C_id& ID, C_date& Date) {
	id_ = ID; date_ = Date;
}
void operator<<(std::ofstream &is, C_relationship &C) {
	is << C.b_value_<<' ';
	is << C.i_typ_<<' ';
	is << C.id_;
	is << ' ';
	is << C.V_.size()<<' ';
	for (auto& x : C.V_) {
		is << '\n';
		is << x;
	}
	is << ' ';
}
void operator>>(std::ifstream& is, C_relationship &C) {
	long long ll_temp;
	int i_iterator;
	C_relation relation;
	is >> C.b_value_;
	is >> C.i_typ_;
	is >> C.id_;
	is >> ll_temp; //ilosc elementow relacje (dzieci)
	for (i_iterator = 0; i_iterator < ll_temp; i_iterator++) {
		is >> relation;
		C.m_set_baby(relation);
	}
}
void C_relationship::m_wiew() {}
C_relationship::~C_relationship() {}
void C_relationship::m_active() { b_value_ = true; }
void C_relationship::m_deactive() { b_value_ = false; }
void C_relationship::m_add_typ(int i_variable) { i_typ_ = i_variable; }
void C_relationship::m_get_typ(int i_variable) { i_variable = i_typ_; }
void C_relationship::m_add_id(C_id& ID) { id_ = ID; }
void C_relationship::m_get_id(C_id& ID) { ID = id_; }
C_relation C_relationship::m_return(int i_value) {
	if(i_value<V_.size())
	return V_[i_value];
	else {
		C_relation relation;
		return relation;
	}
}
void C_relationship::m_set_baby(C_relation& relation) {
	V_.push_back(relation);
}
void C_relationship::m_get_baby(std::vector<C_relation>& relation) {
	relation = V_;
}