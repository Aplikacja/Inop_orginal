//**********************************************************************************************************************************************************//
//	Plik: C_relationship.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_RELATIONSHIP_HPP
#define C_RELATIONSHIP_HPP
#include "C_relation.hpp"
#include "../data/C_date.hpp"
#include <vector>
class C_relationship {
	C_id id_;
	C_date date_;
	std::vector<C_relation> V_;
	bool b_value_;
	int i_typ_;
public:
	C_relationship(); //konstruktor
	C_relationship(C_id& id, C_date& Date); //konstruktor paramerowy
	friend void operator<<(std::ofstream &is, C_relationship &C); //operator do zapisywaia danych
	friend void operator>>(std::ifstream& is, C_relationship &C); //operator do wczytywania danych
	void m_wiew(); // mozna pomicac
	void m_active(); //metoda aktywujaca relacje
	void m_deactive(); //metoda powodujaca ze dana relacja jest niekatywna
	void m_add_typ(int i_variable); //metoda pozwalajaca dodawac do obiektu typu C_relation wartosc okreslajaca typ C_relationship
	void m_get_typ(int i_variable); //metoda pozwalajaca wyciagac informacje o typie relacji z obiektu typu C_relationship
	void m_add_id(C_id& ID); //metoda pozwalajaca dodawac id od obiektu typu C_relationship
	void m_get_id(C_id& ID); //metoda pozwalajaca do pozyskiwania id z obiektów typu C_relationship
	C_relation m_return(int i_value); //metoda zwaracajaca relacje "dziecko"
	void m_set_baby(C_relation& relation); //metoda do dodawanaia relacji typu "dziecko"
	void m_get_baby(std::vector<C_relation>& V_baby);
	~C_relationship(); //destruktor
};
#endif // !C_RELATIONSHIP_HPP