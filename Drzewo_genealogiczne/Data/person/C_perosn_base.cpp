//**********************************************************************************************************************************************************//
//	Plik: C_person_base.hpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_person_base.hpp"

C_person_base::C_person_base() {}
//	first_name = "";
//	last_name = "";
//}
C_person_base::C_person_base(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
	C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs) {
	id_ = ID;
	id_.m_active();
	first_name_ = s_First;
	last_name_ = s_Secend;
	b_sex_ = b_SEX;
	brith_ = Date_brith;
	death_ = Date_death;
	V_relation_ = V_r;
	V_relationship_ = V_rs;
}
C_person_base::C_person_base(C_id ID,bool b_SEX,std::string& s_FIRSTNAME, std::string& s_LASTNAME, C_date& date_brith, C_date& date_death) {
	id_ = ID;
	id_.m_active();
	b_sex_ = b_SEX;
	first_name_ = s_FIRSTNAME;
	last_name_ = s_LASTNAME;
	brith_ = date_brith;
	death_ = date_death;
}
C_person_base::C_person_base(std::string& s_FIRSTNAME, std::string& s_LASTNAME,C_date& date_brith, C_date& date_death ) {
	first_name_ = s_FIRSTNAME;
	last_name_ = s_LASTNAME;
	brith_ = date_brith;
	death_ = date_death;
}
C_person_base::~C_person_base() {}
void operator<<(std::ofstream &is, C_person_base &C) {
	is << ' ';
	is << C.b_sex_;
	is << ' ';
	is << C.id_;
	is << C.first_name_<<"\n";
	is << C.last_name_ << "\n";
	is << C.brith_;
	is << "\n";
	is << C.death_;
	is << '\n' << C.V_relation_.size()<<'\n';
	for (auto& X : C.V_relation_) {
		is << X;
		is << "\n";
	}
	is << C.V_relationship_.size()<<'\n';
	for (auto& X : C.V_relationship_) {
		is << X;
		is << "\n";
	}
}
void C_person_base::m_add_id(C_id& ID) {
	id_ = ID;
}
void C_person_base::m_get_id(C_id& ID) {
	ID = id_;
}
void C_person_base::m_add_sex(bool& SEX) {
	b_sex_ = SEX;
}
void C_person_base::m_get_sex(bool& SEX) {
	SEX = b_sex_;
}
void C_person_base::m_add_date(int i_choice, C_date& DATE) {
	switch (i_choice)
	{
	case D_brith:
		brith_ = DATE;	return;
	case D_death:
		death_ = DATE;	return;
	default:
		return;
	}
}
void C_person_base::m_get_date(int i_choice, C_date& DATE) {
	switch (i_choice)
	{
	case D_brith:
		DATE = brith_; return;
	case D_death:
		DATE = death_; return;
	default: return;
	}
}
std::string C_person_base::m_get_content() {
	return ' ' + first_name_ + ' ' + last_name_ + '\n';
}
void C_person_base::m_add_relation(C_relation& relation) {
	V_relation_.push_back(relation);
}
void C_person_base::m_add_relationship(C_relationship& relation) {
	V_relationship_.push_back(relation);
}
void C_person_base::m_get_V_relation(std::vector<C_relation>& V_r) {
	V_r = V_relation_;
}
void C_person_base::m_get_V_relationship(std::vector<C_relationship>& V_rs) {
	V_rs = V_relationship_;
}
void C_person_base::m_add_V_relation(std::vector<C_relation>& V_r) {
	V_relation_ = V_r;
}
void C_person_base::m_add_V_relationship(std::vector<C_relationship>& V_rs) {
	V_relationship_ = V_rs;
}
bool f_sort_first_name(C_person_base* _left, C_person_base* _right) {
	if (_left->first_name_<_right->first_name_)
		return true;
	return false;
}
bool f_sort_last_name(C_person_base* _left, C_person_base* _right) {
	if (_left->last_name_<_right->last_name_)
		return true;
	return false;
}
bool f_sort_date_brith(C_person_base* _left, C_person_base* _right) {
	if (_left->brith_<_right->brith_)
		return true;
	return false;
}
bool f_sort_date_death(C_person_base* _left, C_person_base* _right) {
	if (_left->death_<_right->death_)
		return true;
	return false;
}
bool f_sort_id(C_person_base* _left, C_person_base* _right) {
	if (_left->id_<_right->id_)
		return true;
	return false;
}
void C_person_base::m_add_first_name(std::string& first) {
	first_name_ = first;
}
void C_person_base::m_get_first_name(std::string& first) {
	first = first_name_;
}
void C_person_base::m_add_last_name(std::string& last) {
	last_name_ = last;
}
void C_person_base::m_get_last_name(std::string& last) {
	last = last_name_;
}
void C_person_base::m_conwert(std::string& s_str) {
	std::string data_brith,
				data_death;
	brith_.m_sidle(data_brith);
	death_.m_sidle(data_death);
	s_str +=  '\t'+first_name_ + " , " + last_name_ + " , " + data_brith + " , " + data_death + ";";
}
void C_person_base::m_down_id() {
	id_.m_down();
}
C_date& C_person_base::m_content_date(int i_choice) {
	switch (i_choice) {
	case p_data_brith:
		return brith_;
	case p_data_death:
		return death_;
	default:
		C_date date;
		return date;
	}
}
C_id& C_person_base::m_content_id(int i_choice) {
	switch (i_choice) {
	case p_id:
		return id_;
	default:
		C_id id;
		return id;
	}
}
std::string& C_person_base::m_content_name(int i_choice) {
	switch (i_choice) {
	case p_first_name:
		return first_name_;
	case p_last_name:
		return last_name_;
	default:
		std::string str="";
		return str;
	}
}
bool& C_person_base::m_content_gender(int i_choice) {
	switch (i_choice) {
	case p_first_name:
		return b_sex_;
	default:
		bool b=NULL;
		return b;
	}
}
std::vector<C_relationship>& C_person_base::m_content_V_relationship(int i_choice) {
	switch (i_choice) {
	case p_relationship:
		return V_relationship_;
	default:
		std::vector<C_relationship> V_relationship;
		return V_relationship;
	}
} //5871071
std::vector<C_relation>& C_person_base::m_content_V_relation(int i_choice) {
	switch (i_choice) {
	case p_relation:
		return V_relation_;
	default:
		std::vector<C_relation> V_relation;
		return V_relation;
	}
}