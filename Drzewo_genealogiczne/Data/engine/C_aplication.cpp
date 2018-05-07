//**********************************************************************************************************************************************************//
//	Plik: C_aplication.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
// 15-03-2018				Lukasz			Dodanie petli nieskonczonej while(true) do metody m_view(). Utworzenie petli switch w celu umieszczenia w niej	//
//											mozliwosci wywolania metod klasy C_silnik_software. Klasa C_aplication przeladowuje klase C_menu				//
//**********************************************************************************************************************************************************//
#include "C_aplication.hpp"


C_aplication::C_aplication(std::string what) {
	m_load_file(what);
};
void C_aplication::m_load_file(std::string s_file) {
	try
	{
		std::ifstream file;
		std::ios_base::iostate exceptionMask = file.exceptions() | std::ios::failbit;
		file.exceptions(exceptionMask);
		file.open(s_file.c_str());

		if (file.good())
		{
			int value, value_II, i, j, k, i_temp;
			std::vector<std::vector<std::string>> V_string;
			std::vector<std::vector<int>> v_klucze;
			std::vector<std::vector<std::vector<int>>> V_procedur;
			std::vector<std::vector<int>> V_proces;
			std::vector<int> v_k;
			std::vector<int> v_proc;
			std::vector<bool> V_b;
			std::vector<int> V_start;
			std::vector<std::string> V_temp;
			std::vector<int> V_typ_menu;
			std::string s_temp;
			int i_temp_II;
			int i_typ_menu;
			int i_temp_procedur;
			int i_size_procedur;
			bool b_temp;
			V_str_.resize(2);
			V_str_[1].resize(size_menu);
			file >> value;
			i_size_ = value;
			for (i = 0; i < value; i++)
			{
				file >> i_typ_menu;
				file >> value_II;
				file >> b_temp;
				file >> i_temp_II;
				V_b.push_back(b_temp);
				V_typ_menu.push_back(i_typ_menu);
				V_temp.clear();
				V_proces.clear();
				v_k.clear();
				for (j = 0; j < value_II; j++)
				{
					file >> i_temp;
					file >> i_size_procedur;
					v_proc.clear();
					for (k = 0; k < i_size_procedur; k++) {
						file >> i_temp_procedur;
						v_proc.push_back(i_temp_procedur);
					}
					s_temp.clear();
					getline(file, s_temp);
					v_k.push_back(i_temp);
					V_temp.push_back(s_temp);
					V_proces.push_back(v_proc);
				}
				V_procedur.push_back(V_proces);
				v_klucze.push_back(v_k);
				V_string.push_back(V_temp);
				V_start.push_back(i_temp_II);
				V_str_[0] = V_string;
			}
			M_.m_loader(V_string, V_b, v_klucze, V_procedur, V_start, V_typ_menu); //ladowanie menu
			for (j = 0; j < value; j++) {
				M_.m_set_str(j, V_str_);
			}
			file.close();
		}
	}
	catch (std::ios_base::failure& ex)
	{
		MessageBox(nullptr, TEXT("Blad podczs wczytywania pliku."), TEXT("Blad!"), MB_OK);
	}
	catch (...)
	{
		MessageBox(nullptr, TEXT("Nierozpoznany blad aplikacji."), TEXT("Blad!"), MB_OK);
	}
}
void C_aplication::m_view() {
	int i_variable=0;
	int i_klucz;
	long long i_id_pointer; //id persona wskaznikowego wzgledem ktorego bedzie rysowane drzewo
	std::vector<int> V_proces;
	std::string s_tree; //nazwa drzewa wokul ktorego zachodza opcje wybierane w menu
	V_proces.push_back(Menu_glowne);
	int i_choice = 1;
	while (true) {
		for (auto& X : V_proces) {

			switch (X)
			{
				case Menu_glowne:
					i_variable = 0;
					i_choice = 1;
				M_.m_view(id_menu_MenuGlowne, i_variable, i_klucz, V_proces, i_choice);
				break;
				case Menu_pewnosci:
					i_variable = 3;
					i_choice = 1;
					M_.m_set_replay(i_variable, id_menu_Menu_pewnosci, Menu_glowne);
					M_.m_view(id_menu_Menu_pewnosci, i_variable, i_klucz, V_proces, i_choice);
					break;
				case M_zarzadzaniatree:
					i_variable = 1;
					i_choice = 1;
					M_.m_set_replay(i_variable, id_menu_zarzadzaniadrzewem, search_tree);
					M_.m_view(id_menu_zarzadzaniadrzewem, i_variable, i_klucz, V_proces, i_choice);
					break;
				case M_zarzadzaniapersonem:
					i_variable = 7;
					i_choice = 1;
					M_.m_set_replay(i_variable, id_menu_zarzadzaniapersonem, searchperson);
					if (M_.m_view(id_menu_zarzadzaniapersonem, i_variable, i_klucz, V_proces, i_choice)) {

					}
					break;
				case Edition_tree:
					i_variable = 10;
					i_choice = 1;
					M_.m_set_replay(i_variable, id_menu_MenuEditTree, search_tree);
					M_.m_view(id_menu_MenuEditTree, i_variable, i_klucz, V_proces, i_choice);
					break;
				case rename_tree: {
					i_variable = 11;
					i_choice = 2;
					std::vector<std::string> V_name;
					V_name.resize(2);
					V_name[0] = s_tree;
					M_.m_set_replay(i_variable, id_menu_MenuRenameTree, Edition_tree);
					if (M_.m_view(id_menu_MenuRenameTree, i_variable, V_name, i_klucz, V_proces, i_choice)) {
						e_soft_.m_edit_name_tree(V_name[1], V_name[0]);
						e_soft_.m_save_tree();
					}
					break; }
				case exit:
					return;
				case load_files: {
					e_soft_.m_load_tree();
				}break;
				case save_files:
					e_soft_.m_save_files(s_tree);
					break;
				case save_tree:
				{
					e_soft_.m_save_tree();
					break;
				}
				case add_person: {
					i_variable = 9;
					i_choice = 1;
					std::vector<std::string> V_dane;
					V_dane.resize(5);
					M_.m_set_replay(i_variable, id_menu_MenuAddPerson, search_tree);
					if (M_.m_view(id_menu_MenuAddPerson, i_variable, V_dane, i_klucz, V_proces, i_choice)) { //lacze dziala wyciaga dane z interface trzeba zrobic funkcje zabezpieczajace
						C_date date_brith, date_death;
						bool b_gender=false;
						date_brith.m_active();
						date_death.m_active();
						date_brith.m_apped(V_dane[2]);
						date_death.m_apped(V_dane[3]);
						switch (V_dane[4][0]) {
						case 'W':
							b_gender = true;
						case 'M':
							b_gender = false;
						}
							e_soft_.m_add_person(b_gender, V_dane[0], V_dane[1],date_brith, date_death);
						break;
					}
					break; }
				case delete_person:
					//	e_soft.m_delete_person(); 
					break;
				case update_person:
					i_variable = 8;
					i_choice = 1;
					M_.m_set_replay(i_variable, id_menu_Menuedycjipersona, M_zarzadzaniapersonem);
					M_.m_view(id_menu_Menuedycjipersona, i_variable, i_klucz, V_proces, i_choice);
					break;
				case new_tree: {
					bool b_what = true;
					std::string s_str;
					i_variable =2;
					M_.m_set_replay(i_variable, id_menu_MenuNewTree, Menu_glowne);
					do {
						if (M_.m_view(id_menu_MenuNewTree, i_variable, s_str, i_klucz, V_proces, i_choice)) {
							e_soft_.m_add_tree(s_str, b_what);
							if (b_what) {
							f_option_clear(h, pos, Written);
								printf("Tworzenie nowego drzewa!\n");
							 f_clear(h, pos, Written);
								break;
							}
							f_option_clear(h, pos, Written);
							printf("Podana nazwa drezwa juz istnieje!\n");
							f_clear(h, pos, Written);
							Sleep(2000);
						}
						else
						break;
					} while (true);

				}break;
				case search_tree: {
					std::string s_str;
					std::vector<std::string> V_string;
					i_variable = 4;
					i_choice = 1;
					e_soft_.m_get_tree(V_string);
					M_.m_set_replay(i_variable, id_menu_MenuSearchTree, Menu_glowne);
					V_str_[1][id_menu_MenuSearchTree] = V_string;
					M_.m_set_str(i_variable, V_str_); //ladowanie menu nazwami drzew
					if (M_.m_view(id_menu_MenuSearchTree, i_variable, s_str, i_klucz, V_proces, i_choice)) {
						s_tree = s_str;
						s_str += ".tree";
						e_soft_.m_load_files(s_str);
						//s_str;
					}
				}break;
				case delete_tree: {
					e_soft_.m_delete_tree(s_tree);

				}break;
				case load_content_tree: {
					e_soft_.m_load_files(*(V_str_[1][0].begin()));
					i_variable = search; //<-przelaczenie do menu wyszukiwania persona
				}break;
				case tree: {
					//----------------czytanie persona----------------------------------
					C_id data;
					C_person_base *person;
					std::vector<std::list<C_person_base*>> V_lista;
					V_lista.resize(4);
					std::list<C_person_base*> lista_temp;
					C_fabric_person Fabric;
					C_id ID;
					C_id id;
					std::string s_first_name;
					std::string s_last_name;
					C_date d_brith;
					C_date d_death;
					bool b_sex;
					int i_typ;
					std::vector<int> V_k;
					std::vector<C_relation> V_relation;
					std::vector<C_relationship> V_relationship;
					std::vector<C_relation> V_relation_temp;
					std::vector<C_relationship> V_relationship_temp;
					e_soft_.m_view(view_search, sort_id, data, lista_temp);
					person = *lista_temp.begin();
					for (auto& x : lista_temp) {
						delete x;
					}
					V_lista.clear();
					person->m_get_V_relation(V_relation);
					person->m_get_V_relationship(V_relationship);
					person->m_get_id(ID);
					for (auto& x_relation : V_relation) {
						x_relation.m_get_id(id);
						x_relation.m_get_typ(i_typ);
						e_soft_.m_view(view_search, sort_id, id, lista_temp);
						//rozkladanie danmych persona na poszczegolne wartosci
						person = *lista_temp.begin();
						person->m_get_first_name(s_first_name);
						person->m_get_last_name(s_last_name);
						person->m_get_date(D_brith, d_brith);
						person->m_get_date(D_death, d_brith);
						person->m_get_sex(b_sex);
						person->m_get_V_relation(V_relation_temp);
						person->m_get_V_relationship(V_relationship_temp);
						//na razie wszystko jest do jednej listy trzeba to ulepszyc
						if (i_typ == r_parents)
							V_lista[0].push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona
						else
							V_lista[1].push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona

					}
					for (auto& x_relationship : V_relationship) {
						std::list<C_person_base*> lista;
						x_relationship.m_get_id(id);
						x_relationship.m_get_typ(i_typ);
						e_soft_.m_view(view_search, sort_id, id, lista_temp);
						//rozkladanie danmych persona na poszczegolne wartosci
						person = *lista_temp.begin();
						person->m_get_first_name(s_first_name);
						person->m_get_last_name(s_last_name);
						person->m_get_date(D_brith, d_brith);
						person->m_get_date(D_death, d_brith);
						person->m_get_sex(b_sex);
						person->m_get_V_relation(V_relation_temp);
						person->m_get_V_relationship(V_relationship_temp);
						//na razie wszystko jest do jednej listy trzeba to ulepszyc
						V_lista[3].push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona
						x_relationship.m_get_baby(V_relation_temp);
						for (auto& x_relation : V_relation) {
							x_relation.m_get_id(id);
							x_relation.m_get_typ(i_typ);
							e_soft_.m_view(view_search, sort_id, id, lista_temp);
							//rozkladanie danmych persona na poszczegolne wartosci
							person = *lista_temp.begin();
							person->m_get_first_name(s_first_name);
							person->m_get_last_name(s_last_name);
							person->m_get_date(D_brith, d_brith);
							person->m_get_date(D_death, d_brith);
							person->m_get_sex(b_sex);
							person->m_get_V_relation(V_relation_temp);
							person->m_get_V_relationship(V_relationship_temp);
							//na razie wszystko jest do jednej listy trzeba to ulepszyc
							lista.push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona
						}
						V_lista.push_back(lista);
					}
					M_.m_set_content_person(0, V_lista); // numer wskazuje na odpowiednie menu!!!
				}break;
				case searchperson: {
					//	case search: {
					C_id data;
					std::string s_str;
					std::string s_temp;
					//int i;
					data.m_update(2);
					i_variable = 5;
					std::list<C_person_base*> lista;
					e_soft_.m_get_list_person_orginal(lista);
				//	e_soft.m_view(view_search, sort_id, data, lista);
					M_.m_set_replay(i_variable, id_menu_MenuSearchPerson, search_tree);
					M_.m_set_content(id_menu_MenuSearchPerson,lista);
					i_choice = 3;
					i_klucz = 5; //wyjatkowo
					if (M_.m_view(id_menu_MenuSearchPerson, i_variable, s_str, i_klucz, V_proces, i_choice)) {
						i_id_pointer = atoi(s_str.c_str());
						//C_id ID();
						//e_soft_.m_view(view_search, sort_id, ID, lista);  //do tego momentu jest dobrze
						//std::cin >> s_temp;
						break;
					}
					//-----wrazie czego------
					//for (auto& x : lista) {
					//	delete x;
				//	}
				//	lista.clear();
					//----------------------
				}break;
				default:
					break;
				}
		}
		if (i_klucz < i_size_) //zabezpiecza przed zawieszaniem menu
			i_variable = i_klucz;
	}

}
C_aplication::~C_aplication() {
	//delete M;
}