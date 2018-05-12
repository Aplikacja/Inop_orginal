//**********************************************************************************************************************************************************//
//	Plik: C_engine_software.cpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_add_person() <- do dodawania nowych osob do drzewa														//
//											- void m_delete_person() <- do usuwania osob z drzewa															//
//											- void m_update_person() <- do edycji danych osob z drzewa														//
//**********************************************************************************************************************************************************//
#include "C_engine_software.hpp"

C_engine_software::C_engine_software() {}
void C_engine_software::m_add_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth) {
	d_Database_.m_add_person(b_SEX,s_first, s_last, d_brith, d_deadth);
} //meoda do przebudowania
void C_engine_software::m_delete_person(long long& i_variable) {
	d_Database_.m_delete_person(i_variable);
} //metoda do przebudowania
void C_engine_software::m_update_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, long long& i_variable) {
	d_Database_.m_update_person(b_SEX,s_first, s_last, d_brith, d_deadth, i_variable);
} //metoda do przebudowy
void C_engine_software::m_add_relation(C_relation& relation, C_id& i_variable) {
	d_Database_.m_add_relation(relation, i_variable);
} //metoda do przebudowy
void C_engine_software::m_add_relationship(C_relationship& relation, C_id& i_variable) {
	d_Database_.m_add_relationship(relation, i_variable);
}
void C_engine_software::m_add_V_relation(std::vector<C_relation>& V_relation, C_id& id) {
	d_Database_.m_add_V_relation(V_relation, id);
}
void C_engine_software::m_add_V_relationship(std::vector<C_relationship>& V_relation, C_id& id) {
	d_Database_.m_add_V_relationship(V_relation, id);
}
void C_engine_software::m_delete_relation(int& i_variable, int& i_var) {
	d_Database_.m_delete_relation(i_variable, i_var);
} //metoda do przebudowy
void C_engine_software::m_delete_relationship(int& i_variable, int& i_var) {
	d_Database_.m_delete_relationship(i_variable, i_var);
} //metoda do przebudowy
void C_engine_software::m_update_relation(C_relation& relation, C_id& i_variable, int i_var) {
	d_Database_.m_update_relation(relation, i_variable, i_var);
} //metoda do przebudowy
void C_engine_software::m_update_relationship(C_relationship& relation, C_id& i_variable, int i_var) {
	d_Database_.m_update_relationship(relation, i_variable, i_var);
} //metoda do przebudowy
C_engine_software::~C_engine_software() {}
void C_engine_software::m_view(int i_typ, int i_var, std::list<C_person_base*>& lista) {

	switch (i_typ) {
		case view_sort:
		{
			switch (i_var) {
				case sort_id: {
					d_Database_.m_sort(f_sort_id); 
					d_Database_.m_get(lista); break;
				}
				case sort_first_name: {
					d_Database_.m_sort(f_sort_first_name); 
					d_Database_.m_get(lista); break;
				}
				case sort_last_name: {
					d_Database_.m_sort(f_sort_last_name);
					d_Database_.m_get(lista); break;
				}
				case sort_date_brith: {
					d_Database_.m_sort(f_sort_date_brith); 
					d_Database_.m_get(lista); break;
				}
				case sort_date_death: {
					d_Database_.m_sort(f_sort_date_death); 
					d_Database_.m_get(lista); break;
				}
				default: break;
			}

		}
		default: break;
	}

}//metoda do przebudowy
void C_engine_software::m_view(int i_typ, int i_var, C_id& ID, std::list<C_person_base*>& lista) {

	switch(i_typ){
		case view_search: {
			switch (i_var) {
				case sort_id: {
					d_Database_.m_search(sort_id, ID, lista); break;
				}
				default: break;
			} break;
		}
		default: break;
	}

} //metoda do przebudowy
void C_engine_software::m_view(int i_typ, int i_var, std::string Person, std::list<C_person_base*>& lista) {

	switch (i_typ) {
	case view_search: {
		switch (i_var) {
		case sort_id: {
			d_Database_.m_search(sort_id, Person, lista); break;
		}
		case sort_first_name: {
			d_Database_.m_search(sort_first_name, Person, lista);
			break;
		}
		case sort_last_name: {
			d_Database_.m_search(sort_last_name, Person, lista); 
			break;
		}
		case sort_date_brith: {
			d_Database_.m_search(sort_date_brith, Person, lista); break;

		}
		case sort_date_death: {
			d_Database_.m_search(sort_date_death, Person, lista); break;
		}
		default: break;
		}
	}
	default: break;
	}

}
void C_engine_software::m_get_list_person_orginal(std::list<C_person_base*>& list) {
	d_Database_.m_get(list);
}
void C_engine_software::m_copy(std::vector<C_person_base*>& V_Person) {
	std::list<C_person_base*> L_person;
	C_fabric_person f;
	V_Person.clear();
	m_get_list_person_orginal(L_person);
	for (auto& X : L_person) {
		V_Person.push_back(f.m_create_peron(r_null,X->m_content_id(p_id),
											X->m_content_gender(p_gender), 
											X->m_content_name(p_first_name), 
											X->m_content_name(p_last_name),
											X->m_content_date(p_data_brith), 
											X->m_content_date(p_data_death),
											X->m_content_V_relation(p_relation), 
											X->m_content_V_relationship(p_relationship)));
	}
}
void C_engine_software::m_copy(std::list<C_person_base*>& L_Person) {
	std::list<C_person_base*> L_person;
	C_fabric_person f;
	L_Person.clear();
	m_get_list_person_orginal(L_person);
	for (auto& X : L_person) {
		L_Person.push_back(f.m_create_peron(r_null, X->m_content_id(p_id),
			X->m_content_gender(p_gender),
			X->m_content_name(p_first_name),
			X->m_content_name(p_last_name),
			X->m_content_date(p_data_brith),
			X->m_content_date(p_data_death),
			X->m_content_V_relation(p_relation),
			X->m_content_V_relationship(p_relationship)));
	}
}