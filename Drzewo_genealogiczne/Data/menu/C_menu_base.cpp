//**********************************************************************************************************************************************************//
//	Plik: C_menu_base.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_base.hpp"
void f_sterowanie(int& x, int& i_klucz,int& i_start, std::vector<int>& v_k);
void f_sterowanie(int& x, std::string& s_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_Size, int i_start_);
void f_option_clear(HANDLE& h, COORD& pos, DWORD& Written);
void f_clear(HANDLE& h, COORD& pos, DWORD& Written);
void f_obsluga_zadrzen_alfabetycznych(int& i_message);
void f_obsluga_zadzren_numerycznych(char& c_message);
void f_obsluga_zdarzen_vk(int& i_message);
void f_discripsion_keys(int i_choice, std::string& data);
inline void f(int i_klawisz, int i_value, unsigned int& i_return);
inline void f_pouse();
C_menu_base::C_menu_base( std::vector<std::vector<std::string>>& v, bool b_value,  std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_proc, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) {
	V_str_.push_back(v);
	b_dinamic_ = b_value;
	V_L_person_ = L_person;
	V_klucz_ = v_k;
	V_procedur_ = V_proc;
	i_start_ = i_iterator;
	V_replay_.resize(size_menu);
};
void C_menu_base::m_load( std::vector<std::vector<std::vector<std::string>>> V) {
	if (b_dinamic_)
	{
		V_str_ = V;
	}
}
void C_menu_base::m_ruch(void(*f)(int& x, int& i_klucz,int& i_start, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, int& i_start, std::vector<int>& v_k) {

	f(i_klawisz, i_klucz, i_start, v_k);
}
void C_menu_base::m_ruch(void(*f)(int& x, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k), int& i_klawisz, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k) {

	f(i_klawisz, i_klucz, i_start, v_k);
}
void C_menu_base::m_ruch(void(*f)(int& x, std::string& i_klucz,std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_size, int i_start_), int& i_klawisz, std::string& i_klucz,std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_size, int i_start_) {

	f(i_klawisz, i_klucz, s_message,i_start, v_k, i_size, i_start_);
}
C_menu_base::~C_menu_base() {};
void C_menu_base::m_get_content( std::vector<std::vector<std::vector<std::string>>>& V_CONTENT) {
	V_CONTENT = V_str_;
}
void C_menu_base::m_set_content( std::vector<std::vector<std::vector<std::string>>>& V_CONTENT) {
	V_str_ = V_CONTENT;
}
void C_menu_base::m_add_perosons(std::vector<std::list<C_person_base*>>& L_person) {
	V_L_person_ = L_person;
}
void f_sterowanie(int& x, int& i_klucz,int& i_start, std::vector<int>& v_k) {
	int i_size = (int)v_k.size();
	int i_message;
	while (true)
	{
		f_pouse();
		f_obsluga_zdarzen_vk(i_message);
		switch (i_message) {
		case vkup:
			x--;
			if (x <= i_start - 1)      // gdy wykracza wraca na koniec
				x = i_size - 1;
			return;
		case vkdown:
			x++;
			if (x >= i_size)       // gdy wykracza poza menu, znow wraca na poczatek
				x = i_start;
			return;
		case vkreturn:
			i_klucz = v_k[x];
			return;
		case vkescape: 
			i_klucz = -2;
			return; 
		}
	}
}
void f_sterowanie(int& x, std::string& s_klucz, int& i_start, std::vector<std::string>& v_k) {
	int i_size = (int)v_k.size();
	int i_message;
	while (true)
	{
		f_pouse();
		f_obsluga_zdarzen_vk(i_message);
			switch (i_message) {
			case vkup:
				x--;
				if (x <= i_start - 1)      // gdy wykracza wraca na koniec
					x = i_size - 1;
				return;
			case vkdown:
				x++;
				if (x >= i_size)       // gdy wykracza poza menu, znow wraca na poczatek
					x = i_start;
				return;
			case vkreturn:
				i_start = 0;
				s_klucz = v_k[x];
				return;
			case vkescape: 
				i_start = -2;
				return; 
			}
	}
}
//ponizsza funkcja przetestowana capslook do poprawy dziala jak cukiereczek
void f_sterowanie(int& x, std::string& s_klucz,std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_Size, int i_start_) {
	int i_message;
	while (true)
	{
		i_start = 1;
		f_pouse();
		f_obsluga_zadrzen_alfabetycznych(i_message);
		switch (i_message) {
		case vkup:
			x--;
			if (x <= i_start)      // gdy wykracza wraca na koniec
				x = i_Size - 1;
			return;
		case vkdown:
			x++;
			if (x >= i_Size)       // gdy wykracza poza menu, znow wraca na poczatek
				x = i_start_;
			return;
		case vkreturn:
			i_start = 0;
			s_klucz = v_k[x];
			return;
		case vkescape:
			i_start = -2;
			return; 
		case vkdelete:
			i_start = 2;
			if(s_message.size()>0)
			s_message.pop_back();
		return;
		case vka:
		case vka1:
		case vka2:
			s_message += 'a';	return;
		case vkb:
		case vkb1:
		case vkb2:
			s_message += 'b';	return;
		case vkc:
		case vkc1:
		case vkc2:
			s_message += 'c';	return;
		case vkd:
		case vkd1:
		case vkd2:
			s_message += 'd';	return;
		case vke:
		case vke1:
		case vke2:
			s_message += 'e';	return;
		case vkf:
		case vkf1:
		case vkf2:
			s_message += 'f';	return;
		case vkg:
		case vkg1:
		case vkg2:
			s_message += 'g';	return;
		case vkh:
		case vkh1:
		case vkh2:
			s_message += 'h';	return;
		case vki:
		case vki1:
		case vki2:
			s_message += 'i';	return;
		case vkj:
		case vkj1:
		case vkj2:
			s_message += 'j';	return;
		case vkk:
		case vkk1:
		case vkk2:
			s_message += 'k';	return;
		case vkl:
		case vkl1:
		case vkl2:
			s_message += 'l';	return;
		case vkm:
		case vkm1:
		case vkm2:
			s_message += 'm';	return;
		case vkn:
		case vkn1:
		case vkn2:
			s_message += 'n';	return;
		case vko:
		case vko1:
		case vko2:
			s_message += 'o';	return;
		case vkp:
		case vkp1:
		case vkp2:
			s_message += 'p';	return;
		case vkq:
		case vkq1:
		case vkq2:
			s_message += 'q';	return;
		case vkr:
		case vkr1:
		case vkr2:
			s_message += 'r';	return;
		case vks:
		case vks1:
		case vks2:
			s_message += 's';	return;
		case vkt:
		case vkt1:
		case vkt2:
			s_message += 't';	return;
		case vku:
		case vku1:
		case vku2:
			s_message += 'u';	return;
		case vkw:
		case vkw1:
		case vkw2:
			s_message += 'w';	return;
		case vkv:
		case vkv1:
		case vkv2:
			s_message += 'v';	return;
		case vkx:
		case vkx1:
		case vkx2:
			s_message += 'x';	return;
		case vky:
		case vky1:
		case vky2:
			s_message += 'y';	return;
		case vkz:
		case vkz1:
		case vkz2:
			s_message += 'z';	return;
		case vkA:
			s_message += 'A';	return;
		case vkB:
			s_message += 'B';	return;
		case vkC:
			s_message += 'C';	return;
		case vkD:
			s_message += 'D';	return;
		case vkE:
			s_message += 'E';	return;
		case vkF:
			s_message += 'F';	return;
		case vkG:
			s_message += 'G';	return;
		case vkH:
			s_message += 'H';	return;
		case vkI:
			s_message += 'I';	return;
		case vkJ:
			s_message += 'J';	return;
		case vkK:
			s_message += 'K';	return;
		case vkL:
			s_message += 'L';	return;
		case vkM:
			s_message += 'M';	return;
		case vkN:
			s_message += 'N';	return;
		case vkO:
			s_message += 'O';	return;
		case vkP:
			s_message += 'P';	return;
		case vkQ:
			s_message += 'Q';	return;
		case vkR:
			s_message += 'R';	return;
		case vkS:
			s_message += 'S';	return;
		case vkT:
			s_message += 'T';	return;
		case vkU:
			s_message += 'U';	return;
		case vkW:
			s_message += 'W';	return;
		case vkV:
			s_message += 'V';	return;
		case vkX:
			s_message += 'X';	return;
		case vkY:
			s_message += 'Y';	return;
		case vkZ:
			s_message += 'Z';	return;
		default:	break;
		}
	}
}
void f_sterowanie_add_person(int& x, std::string& s_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_Size, int i_start_) {
	int i_message;
	bool b_what = false;
	while (true)
	{
		i_start = 1;
		f_pouse();
		f_obsluga_zadrzen_alfabetycznych(i_message);
		switch (i_message) {
		case vkup:
			x-=2;
			if (x < i_start)      // gdy wykracza wraca na koniec
				x = i_Size-2;
			return;
		case vkdown:
			x+=2;
			if (x >= i_Size) {// gdy wykracza poza menu, znow wraca na poczatek
				 x = i_start_;
			}
			return;
		case vkreturn:
			i_start = 0;
			s_klucz = v_k[x];
			return;
		case vkescape:
			i_start = -2;
			return;
		case vkdelete:
			i_start = 2;
			if (s_message.size()>0)
				s_message.pop_back();
			return;
		case vkspace:
			s_message += " "; return;
		case vka:
		case vka1:
		case vka2:
			s_message += 'a';	return;
		case vkb:
		case vkb1:
		case vkb2:
			s_message += 'b';	return;
		case vkc:
		case vkc1:
		case vkc2:
			s_message += 'c';	return;
		case vkd:
		case vkd1:
		case vkd2:
			s_message += 'd';	return;
		case vke:
		case vke1:
		case vke2:
			s_message += 'e';	return;
		case vkf:
		case vkf1:
		case vkf2:
			s_message += 'f';	return;
		case vkg:
		case vkg1:
		case vkg2:
			s_message += 'g';	return;
		case vkh:
		case vkh1:
		case vkh2:
			s_message += 'h';	return;
		case vki:
		case vki1:
		case vki2:
			s_message += 'i';	return;
		case vkj:
		case vkj1:
		case vkj2:
			s_message += 'j';	return;
		case vkk:
		case vkk1:
		case vkk2:
			s_message += 'k';	return;
		case vkl:
		case vkl1:
		case vkl2:
			s_message += 'l';	return;
		case vkm:
		case vkm1:
		case vkm2:
			s_message += 'm';	return;
		case vkn:
		case vkn1:
		case vkn2:
			s_message += 'n';	return;
		case vko:
		case vko1:
		case vko2:
			s_message += 'o';	return;
		case vkp:
		case vkp1:
		case vkp2:
			s_message += 'p';	return;
		case vkq:
		case vkq1:
		case vkq2:
			s_message += 'q';	return;
		case vkr:
		case vkr1:
		case vkr2:
			s_message += 'r';	return;
		case vks:
		case vks1:
		case vks2:
			s_message += 's';	return;
		case vkt:
		case vkt1:
		case vkt2:
			s_message += 't';	return;
		case vku:
		case vku1:
		case vku2:
			s_message += 'u';	return;
		case vkw:
		case vkw1:
		case vkw2:
			s_message += 'w';	return;
		case vkv:
		case vkv1:
		case vkv2:
			s_message += 'v';	return;
		case vkx:
		case vkx1:
		case vkx2:
			s_message += 'x';	return;
		case vky:
		case vky1:
		case vky2:
			s_message += 'y';	return;
		case vkz:
		case vkz1:
		case vkz2:
			s_message += 'z';	return;
		case vkA:
			s_message += 'A';	return;
		case vkB:
			s_message += 'B';	return;
		case vkC:
			s_message += 'C';	return;
		case vkD:
			s_message += 'D';	return;
		case vkE:
			s_message += 'E';	return;
		case vkF:
			s_message += 'F';	return;
		case vkG:
			s_message += 'G';	return;
		case vkH:
			s_message += 'H';	return;
		case vkI:
			s_message += 'I';	return;
		case vkJ:
			s_message += 'J';	return;
		case vkK:
			s_message += 'K';	return;
		case vkL:
			s_message += 'L';	return;
		case vkM:
			s_message += 'M';	return;
		case vkN:
			s_message += 'N';	return;
		case vkO:
			s_message += 'O';	return;
		case vkP:
			s_message += 'P';	return;
		case vkQ:
			s_message += 'Q';	return;
		case vkR:
			s_message += 'R';	return;
		case vkS:
			s_message += 'S';	return;
		case vkT:
			s_message += 'T';	return;
		case vkU:
			s_message += 'U';	return;
		case vkW:
			s_message += 'W';	return;
		case vkV:
			s_message += 'V';	return;
		case vkX:
			s_message += 'X';	return;
		case vkY:
			s_message += 'Y';	return;
		case vkZ:
			s_message += 'Z';	return;
		case vk0:
			s_message += '0'; return;
		case vk1:
			s_message += '1'; return;
		case vk2:
			s_message += '2'; return;
		case vk3:
			s_message += '3'; return;
		case vk4:
			s_message += '4'; return;
		case vk5:
			s_message += '5'; return;
		case vk6:
			s_message += '6'; return;
		case vk7:
			s_message += '7'; return;
		case vk8:
			s_message += '8'; return;
		case vk9:
			s_message += '9'; return;
		default:	break;
		}
	}
}
void f_option_clear(HANDLE& h, COORD& pos, DWORD& Written) {
	system("cls");

	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void f_clear(HANDLE& h, COORD& pos, DWORD& Written) {
	FillConsoleOutputCharacter(h, ' ', 0 * 0, pos, &Written);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void C_menu_base::m_set_str(int i_choice,std::vector<std::string>& v_str) {
	V_str_[1][i_choice] = v_str;
}
void C_menu_base::m_get_str(int i_choice, std::vector<std::string>& v_str) {
	if(i_choice >0&&i_choice < V_str_.size())
	v_str = V_str_[1][i_choice];
}
void f_obsluga_zadrzen_alfabetycznych(int& i_message) {
	unsigned int i_result;
	int i_tab_value[45] = { vkdown,vkup,vkreturn,vkescape,vklshift,vkrshift,vkcapslook,vkdelete,vkspace,vka,
							vkb,vkc,vkd,vke,vkf,vkg,vkh,vki,vkj,vkk,vkl,vkm,vkn,vko,vkp,vkq,vkr,vks,vkt,vku,
							vkv,vkw,vkx,vky,vkz,vk0,vk1,vk2,vk3,vk4,vk5,vk6,vk7,vk8,vk9, };
	int i_tab_key[45] = { VK_DOWN,VK_UP,VK_RETURN,VK_ESCAPE,VK_LSHIFT,VK_RSHIFT,VK_CAPITAL,VK_BACK,VK_SPACE,
							0x041, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x04B, 0x4C, 0x4D, 
							0x4E, 0x4F, 0x50, 0x51,	0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A,
							0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 };
	int i;
	do {
		i_result = 0;
		for (i = 0; i<45; i++)
			f(i_tab_key[i], i_tab_value[i], i_result);
	} while (i_result==0);
	i_message = i_result;
}
void f_obsluga_zdarzen_vk(int& i_message) {
	unsigned int i_result=0;
	int i_tab_value[4] = { vkdown,vkup,vkreturn,vkescape };
	int i_tab_key[4] = { VK_DOWN,VK_UP,VK_RETURN,VK_ESCAPE };
	int i;
	do {
		i_result = 0;
		for (i = 0; i < 26; i++)
			f(i_tab_key[i], i_tab_value[i], i_result);
	
	} while (i_result==0);
	i_message = i_result;
}
void f_obsluga_zadzren_numerycznych(char& c_message) {
	unsigned int i_result;
	int i_tab_value[10] = { vk0,vk1,vk2,vk3,vk4,vk5,vk6,vk7,vk8,vk9};
	int i_tab_key[10] = { 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 };
	int i;
	do {
		i_result = 0;
		for (i = 0; i < 26; i++)
			f(i_tab_key[i], i_tab_value[i], i_result);
		switch (i_result) {
		case vk0:
			c_message = '0'; return;
		case vk1:
			c_message = '1'; return;
		case vk2:
			c_message = '2'; return;
		case vk3:
			c_message = '3'; return;
		case vk4:
			c_message = '4'; return;
		case vk5:
			c_message = '5'; return;
		case vk6:
			c_message = '6'; return;
		case vk7:
			c_message = '7'; return;
		case vk8:
			c_message = '8'; return;
		case vk9:
			c_message = '9'; return;
		}
	} while (true);
}
inline void f(int i_klawisz, int i_value, unsigned int& i_return) {
	i_return += ((bool)GetAsyncKeyState(i_klawisz)) * i_value;
}
inline void f_pouse() {
	Sleep(150);
}
void C_menu_base::m_set_replay(int i_choice, int i_replay) {
	V_replay_[i_choice] = i_replay;
}
void C_menu_base::m_get_replay(int i_choice, int& i_replay) {
	i_replay = V_replay_[i_choice];
}
void f_discripsion_keys(int i_choice, std::string& data) {
	switch (i_choice)
	{
	case 0:
	case 2:
	case 3:
	case 4:
	case 7:
	case 11:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	{
		data = "strzalka w dol pozwala na przejscie do kolejnej opcji menu";
		data += "strzalka w gore pozwala na przejscie do poprzedniej opcji menu";
		data	+= "enter-aktywuje opcje";
			break;
	}
	case 1:
	{
		data = "strzalka w dol pozwala na przejscie do kolejnego drzewa";
		data += "strzalka w gore pozwala na przejscie do wczesniejszego drzewa";
		data += "enter-aktywuje opcje";
			break;
	}
	case 8:
	case 21:
	{
		data = "strzalka w dol pozwala na przejscie do kolejnej osoby";
		data += "strzalka w gore pozwala na przejscie do wczesniejszej osoby";
		data += "enter-aktywuje opcje";
			break;
	}

	case 19:
	case 20:
	{
		data = "strzalka w dol pozwala na przejscie do kolejnego realcji";
		data += "strzalka w gore pozwala na przejscie do wczesniejszego realcji";
		data += "enter-aktywuje opcje";
			break;
	}
	case 5:
	case 6:
	case 10:
	case 12:
	case 18:
	{
		data = "strzalka w dol pozwala na przejscie do kolejnego ";
		data += "strzalka w gore pozwala na przejscie do wczesniejszego ";
		data += "dozwolone znaki A-Z";
		data += "dozwolone znaki a-z";
		data += "enter-aktywuje opcje";
		data += "Spacja dodatkowe opcje";
			break;
	}
	case 9:
	{
		data = "strzalka w dol pozwala na przejscie do kolejnego ";
		data += "strzalka w gore pozwala na przejscie do wczesniejszego";
		data += "strzalka w prawo pozwala na przejscie do kolejnego poziomu ";
		data += "strzalka w lewo pozwala na przejscie do wczesniejszego poziomu";
		data += "enter-wyswietl drzewo dla persona";
		data += "Spacja dodatkowe opcje";

			break;
	}

	}
}

