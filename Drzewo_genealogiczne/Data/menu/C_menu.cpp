//**********************************************************************************************************************************************************//
//	Plik: C_menu.cpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu.hpp"

C_menu::C_menu() {
	//	Tab_menu = new Menu_base*[i_value];
};
void C_menu::m_loader(std::vector<std::vector<std::string>> v_s, std::vector<bool> v_b, std::vector<std::vector<int>> v_k) {
	Tab_menu = new C_Menu_base*[v_s.size()];
	size = v_s.size(); // przepisanie rozmiaru vectora
	std::vector<bool>::iterator it = v_b.begin(); //stworzenie iteratora od vectora boola
	std::vector<std::vector<int>>::iterator it_i = v_k.begin(); //stworzenie iteratora do vector�w typu int
	int i; //int iterator fora
	for (i = 0; i < v_s.size(); i++) {
		Tab_menu[i] = f.m_Create_menu(1, *it, v_s[i], *it_i);
		it_i++;
		it++;
	}
}
void C_menu::m_view(int& i_variable, int& i_klucz) {
		if (i_variable >= 0 && i_variable < size) {
			Tab_menu[i_variable]->m_view(i_variable, i_klucz); //do rozwoju trza zaprojektowac lejalt menu
		}
}
C_menu::~C_menu() {
	delete[]Tab_menu;
}