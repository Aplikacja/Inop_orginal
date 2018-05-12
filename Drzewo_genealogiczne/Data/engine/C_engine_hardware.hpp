//**********************************************************************************************************************************************************//
//	Plik: C_engine_hardware.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_load_files() <- do wczytywania drzewa z pliku															//
//											- void m_save_files() <- do zapisywania drzewa do pliku															//
//**********************************************************************************************************************************************************//
#ifndef C_ENGINE_HARDWARE_HPP
#define C_ENGINE_HARDWARE_HPP
#include "define.hpp"
#include "../person/C_fabric_person.hpp"
#include "C_db.hpp"
#include "C_tree.hpp"
#include <set>
//bool f_sort_tree(std::string _Left, std::string _Right);
void f_creative_file_tree(std::string s_data); //metoda do tworzenia pliku drzewa
class C_engine_hardware {
protected:
	C_db d_Database_; //baza danych
	C_tree t_tree_; //drzewo - to cos bedzie realizowac algorytm poruszania sie po drzewie
	std::set<std::string> S_tree_;
public:
	C_engine_hardware(); //konstruktor
	void m_load_files(std::string& s_str); //metoda do przebudowy
	void m_save_files(std::string s_data);	//metoda do przebudowy
	void m_sort(bool(*F)(C_person_base* _left, C_person_base* _right)); //metoda do sortowania bazy danych
	void m_add_tree(std::string& s_data, bool& b_what); //metoda do dodawania nowych drzew
	void m_get_tree(std::vector<std::string>& V_str);
	void m_load_tree(); //metoda do wczytywania listy drzew
	void m_edit_name_tree(std::string _new, std::string _old); //metoda do edycji nazw drzewa
	void m_save_tree(); //metoda do zapisywania listy drzew
	void m_delete_tree(std::string s_data); //metoda do usuwania drzewa
	~C_engine_hardware(); //destruktor
};
#endif // !C_ENGINE_HARDWARE_HPP