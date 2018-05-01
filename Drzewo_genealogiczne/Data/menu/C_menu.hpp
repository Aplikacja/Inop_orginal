//**********************************************************************************************************************************************************//
//	Plik: C_menu.hpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_HPP
#define C_MENU_HPP
#include "C_fabric_menu.hpp"
#include <list>
class C_menu {
	C_fabric_menu f_;
	//std::list<C_person_base*> lista;
	int i_size;
	std::vector<std::string> V_str_;
	C_menu_base** Tab_menu_;
public:
	C_menu(); //konstruktor
	void m_loader(std::vector<std::vector<std::string>>& v_s, std::vector<bool>& v_b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<std::vector<int>>>& V_procedur,std::vector<int>& i_iterator, std::vector<int>& V_typ_menu); 
	void m_view(int i_id_menu,int& i_variable, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	void m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	void m_set_content(int i_choice,std::list<C_person_base*>& lista);
	void m_set_str(int i_variable,std::vector<std::vector<std::vector<std::string>>>& v_str);
	void m_get_str(int i_variable,std::vector<std::vector<std::vector<std::string>>>& v_str);
	void m_set_content_person(int i_choice,std::vector<std::list<C_person_base*>>& lista);
	~C_menu(); //destruktor
};
#endif // !C_MENU_HPP