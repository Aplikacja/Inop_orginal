#include "C_menu_search.hpp"
void f_edge(unsigned int& i_iter_down, unsigned int& i_iter_up, int i_x, int i_size, int i_start);
C_menu_search::C_menu_search(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person):C_menu_base(V, b, v_k, V_procedur, i_iterator, L_person) {}
bool C_menu_search::m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { //dopasowac zwracanie stringa z metody!!
	int i_x = i_start_;
	int i_sta = i_start_;
	int ptr;
	unsigned int i_iter_down;
	unsigned int i_iter_up;
	int i_replay;
	std::vector<int> V_k;
	std::string s_temp;
	std::vector<std::string> V_string;
	std::vector<std::vector<std::string>>::iterator it_s;
	for (auto& Y : V_str_[0][i_id_menu]) //eksperymeny bylo i_klucz
		V_string.push_back(Y);
	for  (auto& Y: V_str_[1][i_id_menu])
		V_string.push_back(Y);
	V_k = *V_klucz_.begin();
	switch (i_choice) {
	case 1: {

		f_option_clear(h, pos, Written);
		while (true) {
			//f_option_clear(h, pos, Written);
			ptr = 0;
			f_edge(i_iter_down, i_iter_up, i_x, (int)V_string.size(), i_start_);
			for (auto& x : V_string) {
				{
					if (ptr < i_start_) {
						printf(x.c_str()); printf("\n");
						ptr++; continue;
					}
					else if (ptr < (int)i_iter_down) { ptr++; continue; }
					else if (ptr >= (int)i_iter_up) break;
				 if (ptr == i_x) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					ptr++;
				}
			}
				f_clear(h, pos, Written);
				m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string);
				if (i_sta <= 0) {
					switch (i_sta) {
					case 0: {
						s_result = s_temp;
						V_proces = V_procedur_[0];
						return true; }
					case -2: {
						//zaimplementowane do cofania sie do poprzedniego menu
						V_proces.clear();
						this->m_get_replay(i_id_menu, i_replay);
						V_proces.push_back(i_replay);
						return false; }
					default:
						break;
					}
				}
			};
		}break;
	case 3: {
//		char * c_temp;
		//f_option_clear(h, pos, Written);
		while (true) {
			f_option_clear(h, pos, Written);
			ptr = 0;
			f_edge(i_iter_down, i_iter_up, i_x, (int)V_string.size(), i_start_);
			for (auto& x : V_string) {
				if (ptr < i_start_) {
					printf(x.c_str()); printf("\n");
					ptr++; continue;
				}
				else if (ptr < (int)i_iter_down) { ptr++; continue; }
				else if (ptr >= (int)i_iter_up) break;
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf(x.c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(x.c_str()); printf("\n");
				ptr++;

			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string);
			if (i_sta <= 0) {
				switch (i_sta) {
				case 0: {
					--i_x; //korekta!
					std::ostringstream ss;
					ss << i_x;
					s_result = ss.str();
					V_proces = V_procedur_[0];
					return true; }
				case -2: {
					//zaimplementowane do cofania sie do poprzedniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false; }
				default:
					break;
				}
			}
		};
	}break;
	case 2:

	{
		//f_option_clear(h, pos, Written);
		while (true) {
			f_option_clear(h, pos, Written);
			ptr = i_start_;
			f_edge(i_iter_down, i_iter_up, i_x, (int)it_s->size(), i_start_);
			it_s = V_str_[1].begin();
			for (auto& x : *it_s) {
				if (ptr < i_start_) {

					printf(x.c_str()); printf("\n");
					ptr++; continue;
				}
				else if (ptr < (int)i_iter_down) { ptr++; continue; }
				else if (ptr >= (int)i_iter_up) { break; }
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf(x.c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(x.c_str()); printf("\n");
				ptr++;
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string);
			if (i_sta <= 0) {
				switch (i_sta) {
				case 0: {
					s_result = s_temp;
					V_proces = V_procedur_[0];
					return true; }
				case -2: {
					//zaimplementowane do cofania sie do poprzedniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false; }
				default:
					break;
				}
			}
		};
	}break;
	case 4: {

		f_option_clear(h, pos, Written);
		while (true) {
			//f_option_clear(h, pos, Written);
			ptr = 0;
			f_edge(i_iter_down, i_iter_up, i_x, (int)V_string.size(), i_start_);
			for (auto& x : V_string) {
				{
					if (ptr < i_start_) {
						printf(x.c_str()); printf("\n");
						ptr++; continue;
					}
					else if (ptr < (int)i_iter_down) { ptr++; continue; }
					else if (ptr >= (int)i_iter_up) break;
					if (ptr == i_x) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					ptr++;
				}
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string);
			if (i_sta <= 0) {
				switch (i_sta) {
				case 0: {
					i_klucz = i_x-i_start_;
					V_proces = V_procedur_[0];
					return true; }
				case -2: {
					//zaimplementowane do cofania sie do poprzedniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false; }
				default:
					break;
				}
			}
		};
	}break;
	default: break;
	}
	return false;
} //metoda wysiwetlajaca
bool C_menu_search::m_view(int i_id_menu, int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) { return false; }
bool C_menu_search::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { return false; }
C_menu_search::~C_menu_search() {} //destruktor
void f_edge(unsigned int& i_iter_down, unsigned int& i_iter_up, int i_x, int i_size, int i_start) {
	if (i_size > size_list_view * 2) {
		if (i_x < size_list_view+i_start) {
			i_iter_down = i_start;
			i_iter_up = 2 * size_list_view+i_start;
			return;
		}
		else if (i_x < i_size - size_list_view)
		{
			if (0 < i_x - size_list_view)
				i_iter_down = i_x - size_list_view;
				i_iter_up = i_x + size_list_view;
		}
		else {
			i_iter_down = i_size - 2* size_list_view;
			i_iter_up = i_size;
		}
	}
	else
	{
		i_iter_down = 0;
		i_iter_up = i_size;
		return;
	}
}