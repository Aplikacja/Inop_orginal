//**********************************************************************************************************************************************************//
//	Plik: C_person_base.hpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_PERSON_BASE_HPP
#define C_PERSON_BASE_HPP
#include <vector>
#include "../data/C_id.hpp"
#include "../data/C_date.hpp"
#include "../relation/C_relationship.hpp"
#include "../relation/C_relation.hpp"
class C_person_base {
protected:
	C_id id_; //zmienna id, sluzy do identyfikacji obiektu
	bool b_sex_; //wartosc bool b_SEX odpowiada za przechowywanie wartosci o pluci osobnika (true kobieta, fale Facet)
	std::string first_name_; //zmienna string first_name przechowuje wartosc o imieniu
	std::string last_name_; //zmienna string last_name przechowuje wartosci o nazwisku
	C_date brith_; //zmienna C_date przechowuje informacje o dacie urodzenia
	C_date death_; //zmienna C_date przechowuje informacje o dacie smierci
	std::vector<C_relationship> V_relationship_; //ten typ:P przechowuje rodzaj relacji typu(C_relationship "zwiazki") [partnera, date slubu i dzieci ze zwiazku]
	std::vector<C_relation> V_relation_; //ten typ:P przechowuje rodzaj relacji typu(C_relation "zwiazki") [typ relacji i id persona na drugim koncu relacji]
	std::string m_get_content(); //prywatna metoda zwaracajaca string z imieniem i nazwiskiem perosna
public:
	C_person_base();	//konstruktor
	C_person_base(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
					C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs); //konstruktor parametrowy wymagany do klasy fabric_person
	C_person_base(C_id ID, bool b_SEX, std::string& s_FIRSTNAME, std::string& s_LASTNAME, C_date& date_brith, C_date& date_death); //konstruktor parametrowy (...)
	C_person_base(std::string& s_FIRSTNAME, std::string& s_LASTNAME, C_date& date_brith, C_date& date_death); //konstruktor parametrowy (...)
	void m_add_id(C_id& ID); //metoda pozwalajaca wstawic do obiektu klasy C_person i jej pochodnych wartosc ID
	void m_get_id(C_id& ID); //metoda pozwalacjaca na wyciaganie wartosci id z klasy C_person i ich pochodnych
	void m_add_sex(bool& SEX); //metoda pozwalajaca wstawic do obiektu klasy C_person i jej pochodnych wartosc bool okreslajaca plec perosna
	void m_get_sex(bool& SEX); //metoda pozwalajaca wyciagnac wartosc okreslajaca plec (...)
	void m_add_first_name(std::string& first); //metoda pozwalajaca wstawic wartosc imienia (...)
	void m_get_first_name(std::string& first); //metoda pozwalajaca wyciagnac z obiektu informacje o imieniu (...)
	void m_add_last_name(std::string& last); //metoda pozwalajaca wstawic wartosc nazwiska (...)
	void m_get_last_name(std::string& last); //metoda pozwalajaca wyciagnac z obiektu informacje o nazwisku (...)
	void m_add_date(int i_choice, C_date& DATE); //metaoda pozwalacaja wstawic wartosc okreslajaca date (urodzenia/smierci) o tym do ktorej zmiennej daty wticujemy wartrosc DATE decyduje parametr metody int i_choice
	void m_get_date(int i_choice, C_date& DATE); //metoda pozwalajaca wyciagac wartosc zmiennych data, o tym z ktorej zmiennej te informacji wyciagnac decyduje parametr int i_choice
	void m_add_relation(C_relation& relation); //metoda pozwalajaca dodawac obiekty typu C_relation do obiektu klasy Person (...)
	void m_add_relationship(C_relationship& relation); //metoda pozwalajaca dodawac obiekty typu C_relationship do obiektu klasy Person (...)
	void m_get_V_relation(std::vector<C_relation>& V_r);  //metoda pozwalajaca wyciagnac vektor typu C_relation z obiektu klasy Perosn (...)
	void m_get_V_relationship(std::vector<C_relationship>& V_rs); //metoda pozwalaca wyciagnac vetor C_relationship z obiektu klasy Perosn (...)
	void m_add_V_relation(std::vector<C_relation>& V_r); //metoda pozwalajaca na dodawanie vektora typu C_relation do obiektu klasy Perosn (...)
	void m_add_V_relationship(std::vector<C_relationship>& V_rs); //metoda pozwalajaca na dodawanie vektora typu C_relationship do obiektu klasy Perosn (...)
	void m_conwert(std::string& s_str); //metoda pozwalajaca wycagnac dane z perosna za pomoca typu string. Metoda ta wykorzystywana jest w wyborze Perosna w interface
	C_date& m_content_date(int i_choice);
	C_id& m_content_id(int i_choice);
	std::string& m_content_name(int i_choice);
	bool& m_content_gender(int i_choice);
	std::vector<C_relationship>& m_content_V_relationship(int i_choice);
	std::vector<C_relation>& m_content_V_relation(int i_choice);
	void m_down_id();
	virtual std::string m_view()=0; //metoda wirtualna sprawiajaca ze klasa C_perosn jest klasa abstrakcyjna
	friend void operator<<(std::ofstream &is, C_person_base &C); //przeciazenie operatora przesuniecia botowego na output pozawalajaca na zapis danych Perosna do pliku 
	friend bool f_sort_first_name(C_person_base* _left, C_person_base* _right); //zaprzyjazniona funcja zwaracajaca zwartosc bool, porownujaca dwa imienia (napisana do sortowania std::list<C_perosn_base*>)
	friend bool f_sort_last_name(C_person_base* _left, C_person_base* _right); //zaprzyjazniona funcja zwaracajaca zwartosc bool, porownujaca dwa nazwiska (napisana do sortowania std::list<C_perosn_base*>)
	friend bool f_sort_date_brith(C_person_base* _left, C_person_base* _right); //zaprzyjazniona funcja zwaracajaca zwartosc bool, porownujaca dwie daty urodzenia (napisana do sortowania std::list<C_perosn_base*>)
	friend bool f_sort_date_death(C_person_base* _left, C_person_base* _right); //zaprzyjazniona funcja zwaracajaca zwartosc bool, porownujaca dwie daty smierci (napisana do sortowania std::list<C_perosn_base*>)
	friend bool f_sort_id(C_person_base* _left, C_person_base* _right); //zaprzyjazniona funcja zwaracajaca zwartosc bool, porownujaca dwa id (napisana do sortowania std::list<C_perosn_base*>)
	~C_person_base(); //destruktor
};
#endif // !C_PERSON_BASE_HPP

