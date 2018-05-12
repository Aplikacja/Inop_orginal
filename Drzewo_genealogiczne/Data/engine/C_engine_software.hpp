//**********************************************************************************************************************************************************//
//	Plik: C_engine_software.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_add_person() <- do dodawania nowych osob do drzewa														//
//											- void m_delete_person() <- do usuwania osob z drzewa															//
//											- void m_update_person() <- do edycji danych osob z drzewa														//
//**********************************************************************************************************************************************************//
#ifndef C_ENGINE_SOFTWARE_HPP
#define C_ENGINE_SOFTWARE_HPP
#include "C_engine_hardware.hpp"
class C_engine_software :public C_engine_hardware {
public:
	C_engine_software(); //konstruktor
	void m_add_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth); //meoda pozwalajaca dodawac nowa osobe do bazy danych
	void m_delete_person(long long& i_variable); //metoda pozwalajaca usunac osobe z bazy danych 
	void m_update_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, long long& i_variable); //metoda pozwalajaca updatowac (podmieniac) dane perosna wskazanego
	//za pomoca argumentu int i_variable
	void m_add_relation(C_relation& relation, C_id& i_variable); //metoda pozwalajaca dodawac obietktu typu C_relation do wskazanego przez argument int i_variable do obiektu Person 
	void m_add_relationship(C_relationship& relation, C_id& i_variable); //metoda pozwalajaca dodawac obietktu typu C_relationship do wskazanego przez argument int i_variable do obiektu Person 
	void m_add_V_relation(std::vector<C_relation>& relation, C_id& i_variable); //metoda pozwalajaca dodawac obietktu typu C_relation do wskazanego przez argument int i_variable do obiektu Person 
	void m_add_V_relationship(std::vector<C_relationship>& relation, C_id& i_variable); //metoda pozwalajaca dodawac obietktu typu C_relationship do wskazanego przez argument int i_variable do obiektu Person
	void m_delete_relation(int& i_variable, int& i_var); //metoda pozwalajaca usunac obiekt typu C_relation z obiektu Person
	void m_get_list_person_orginal(std::list<C_person_base*>& list);
	void m_delete_relationship(int& i_variable, int& i_var); //metoda pozwalajaca usunac obiekt typu C_relationship z obiektu Person
	void m_update_relation(C_relation& relation, C_id& i_variable, int i_var); //metoda pozwalajaca uaktualnic obiekt typu C_relation z obiektu Person
	void m_update_relationship(C_relationship& relation, C_id& i_variable, int i_var); //metoda pozwalajaca uaktualnic obiekt typu C_relationship z obiektu Person
	void m_copy(std::vector<C_person_base*>& V_Person);
	void m_copy(std::list<C_person_base*>& L_Person);
	void m_view(int i_typ, int i_var, std::list<C_person_base*>& lista); //metoda do sortowania i wyszkiwania
	void m_view(int i_typ, int i_var, C_id& Person, std::list<C_person_base*>& lista); //metoda do sortowaia i wyszukiwania
	void m_view(int i_typ, int i_var, std::string Person, std::list<C_person_base*>& lista); //metoda do sortowania i wyszukiwania
	~C_engine_software(); //destruktor
};
#endif // !C_ENGINE_SOFTWARE_HPP