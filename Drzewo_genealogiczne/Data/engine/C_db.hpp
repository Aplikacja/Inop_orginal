//**********************************************************************************************************************************************************//
//	Plik: C_db.hpp																											Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_DB_HPP
#define C_DB_HPP
#include <list>
#include "../person/C_person_null.hpp"
bool f_sort_first_name(C_person_base* _left, C_person_base* _right);
bool f_sort_last_name(C_person_base* _left, C_person_base* _right);
bool f_sort_date_brith(C_person_base* _left, C_person_base* _right);
bool f_sort_date_death(C_person_base* _left, C_person_base* _right);
bool f_sort_id(C_person_base* _left, C_person_base* _right);
bool f_comparison(std::string& s_L, std::string& s_R);
bool f_comparison(long long& ll_L, long long& ll_R);
template<class T>
void f_szukaj(int i_typ, int& i_SIZE, int& i_var, int& i_iterator,
	int& i_size, std::list<C_person_base*>& List, std::list<C_person_base*>::iterator& it,
	std::list<C_person_base*>::iterator& it_start, T& s_pointer, T& s_szukana); //funkcja do szukania
void f_typ(int i_typ, long long& t_data, std::list<C_person_base*>::iterator& it); //funkcja do wyszukiwania
void f_typ(int i_typ, std::string& s_data, std::list<C_person_base*>::iterator& it); //funkcjia do wyszukiwania
int f_sprawdzanie_gora(int& i_SIZE, int& i_iterator, int& i_size); //funckja do wyszukiwania
int f_sprawdzanie_dol(int& i_SIZE, int& i_iterator, int& i_size); //funkcja do wyszukiwania
int f_sprawdzanie(int& i_SIZE, int& i_iterator, int& i_size); //funkcja do wyszukiwania
class C_db {
	std::list<C_person_base*> L_person_;
	long long ID_MAIN_;
	void m_delete_base();
public:
	C_db(); //konstruktor
	void m_size(int& i_var); //metoda do pobierania rozmiaru bazy danych
	void m_add_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth); //metoda do dodawania do listy persona
	void m_update_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, long long& i_variable); //metoda do edycji perosna w liscie
	void m_add_relation(C_relation& relation, C_id& i_variable); //metoda do dodawania relacji do bazy danych do wybranego perosna 
	void m_add_relationship(C_relationship& relation, C_id& i_variable);  //metoda do dodawania zwiazku(relationship) do bazy danych do wybranego perosna 
	void m_add_V_relation(std::vector<C_relation>& relation, C_id& i_variable); //metoda do dodawania relacji do bazy danych do wybranego perosna 
	void m_add_V_relationship(std::vector<C_relationship>& relation, C_id& i_variable);  //metoda do dodawania zwiazku(relationship) do bazy danych do wybranego perosna 
	void m_delete_person(long long& i_variable); //usuwania persona z bazy danych
	void m_delete_relation(int& i_variable, int& i_var); //metoda do usuwania relacji z wybranego perosna
	void m_delete_relationship(int& i_variable, int& i_var); //metoda do usuwania zwiazku z wybranego persona
	void m_update_relation(C_relation& relation, C_id& i_variable, int i_var);  //metoda do zaktualizowania relacji u danego persona
	void m_update_relationship(C_relationship& relation, C_id& i_variable, int i_var); //metoda do zaktualizowania zwiazku u danego persona
	void m_get(std::list<C_person_base*>& lista); //metoda zwracajaca liste persona
	void m_load(std::ifstream& is); //metoda wczytujaca dane z pliku
	void m_sort(bool(*F)(C_person_base* _left, C_person_base* _right)); //metoda do sortowania listy
	void m_search(int i_choice, C_id& Person, std::list<C_person_base*>& List); //metoda do wyszukiwania
	void m_search(int i_choice, std::string s_szukana, std::list<C_person_base*>& List); //metoda do wyszukiwania
	void m_search_specjal(C_id Person, std::list<C_person_base*>& List); //metoda do wyszukiwania specjalnego
	~C_db(); //destruktor
};
#endif // !C_DB_HPP