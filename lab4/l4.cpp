/*﻿#include <iostream>

struct ActionAndButton{
	std::string act;
	std::string button;
};

class Keyboard {
   public:
	   Keyboard() {
		
	   }
	   ActionAndButton actionAndButton[100];
	   int t = 0;



	   void NewAct() {
		   std::cout << "Введите название кнопки/кнопок" << std::endl;
		   std::cin >> actionAndButton[t].button;
		   std::cout << "Введите действие" << std::endl;
		   std::cin >> actionAndButton[t].act;
		   t++;
	   }

	   void PressButton(std::string s) {
		   bool tmp = 0;
		   for (int i = 0; i < t; i++) {
			   if (s == actionAndButton[i].button) {
				   std::cout << actionAndButton[i].act << std::endl;
				   tmp = 1;
				   i = t;
			   }
		   }
		   if (tmp == 0) {
			   std::cout << "У этой кнопки нет действия. Хотите его добавить" << std::endl;
			   std::cout << "0. Нет" << std::endl;
			   std::cout << "1. Да" << std::endl;
			   int i;
			   std::cin >> i;
			   if (i == 1) {
				   this->NewAct();
			   }
		   }
	   }
	   

 

	   void Help() {
		   for (int i = 0; i < t; i++) {
			   std::cout << actionAndButton[i].button + " "+ actionAndButton[i].act << std::endl;
		   }
	   }

	  
private:
	
};

class Workflow {
public:
	Workflow() {
	}


	void Undo(Keyboard& m_key) {
		std::cout << "НА одно действие назад" << std::endl;
		if (nnumberOfActions == 0) {
			m_key.t--;
		}
		for (int i = 0; i < m_key.t; i++) {
			if (Action[nnumberOfActions - 1].act == m_key.actionAndButton[i].act and Action[nnumberOfActions - 1].button == m_key.actionAndButton[i].button) {
				nnumberOfActions--;
				m_key.t--;
				i = m_key.t;
			}
			else if (Action[nnumberOfActions - 1].act != m_key.actionAndButton[i].act and Action[nnumberOfActions - 1].button == m_key.actionAndButton[i].button) {
				m_key.actionAndButton[i].act = Action[nnumberOfActions - 1].act;
				nnumberOfActions--;
				i = m_key.t;
			}
		}
	}


	void Reassignment(std::string s, Keyboard& m_key) {
		std::cout << "Назначьте этой кнопке другое действие" << std::endl;
		bool tmp = 0;
		for (int i = 0; i < m_key.t; i++) {
			if (s == m_key.actionAndButton[i].button) {
				Action[nnumberOfActions] = m_key.actionAndButton[i];
				nnumberOfActions++;
				std::cin >> m_key.actionAndButton[i].act;
				tmp = 1;
				i = m_key.t;
			}
		}
		if (tmp == 0) {
			std::cout << "У этой кнопки нет действия. Хотите его добавить" << std::endl;
			std::cout << "0. Нет" << std::endl;
			std::cout << "1. Да" << std::endl;
			int i;
			std::cin >> i;
			if (i == 1) {
				m_key.NewAct();
			}
		}

	}


private:

	ActionAndButton Action[200];
	int nnumberOfActions = 0;
};



int main()
{
	setlocale(LC_ALL, "Russian");
	
	Keyboard Key;
	Workflow work;
	Key.NewAct();
	Key.NewAct();
	Key.Help();
	std::cout << "Введите клавишу, которую ранее нажали" << std::endl;
	std::string s;
	std::cin >> s;
	work.Reassignment(s, Key);
	Key.Help();
	work.Undo(Key);
	Key.Help();

}*/


#include <iostream>
struct ActionAndButton {
	std::string act;
	std::string button;
	std::string DellAct;
};

class Keyboard {
public:
	Keyboard() {

	}
	ActionAndButton actionAndButton[100];
	int t = 0;



	void NewAct(std::string a,std::string b, std::string c) {
		actionAndButton[t].button = a;
	    actionAndButton[t].act = b;
		actionAndButton[t].DellAct = c;
		t++;
	}

	void PressButton(std::string s) {
		bool tmp = 0;
		for (int i = 0; i < t; i++) {
			if (s == actionAndButton[i].button) {
				std::cout << actionAndButton[i].act << std::endl;
				tmp = 1;
				i = t;

			}
		}
		/*if (tmp == 0) {
			std::cout << "У этой кнопки нет действия. Хотите его добавить" << std::endl;
			std::cout << "0. Нет" << std::endl;
			std::cout << "1. Да" << std::endl;
			int i;
			std::cin >> i;
			if (i == 1) {
				this->NewAct();
			}
		}*/
	}




	void Help() {
		for (int i = 0; i < t; i++) {
			std::cout << actionAndButton[i].button + " " + actionAndButton[i].act << std::endl;
		}
	}


private:

};

class Workflow {
public:
	Workflow() {
	}


	void Undo(Keyboard& m_key) {
		
		if (nnumberOfActions != 0) {


			for (int i = 0; i < m_key.t; i++) {
				if (Action[nnumberOfActions - 1] == m_key.actionAndButton[i].act) {
					Action[nnumberOfActions] = m_key.actionAndButton[i].DellAct;
					nnumberOfActions--;
					m_key.t--;
					i = m_key.t;
				}
			}
		}
	}
	void Press(Keyboard& m_key, std::string s){

		for (int i = 0; i < m_key.t; i++) {
			if (s == m_key.actionAndButton[i].button) {
				nnumberOfActions++;
				Action[nnumberOfActions] = m_key.actionAndButton[i].act;
				nnumberOfActions++;
			}
		}
	}

	void Reassignment(std::string s, Keyboard& m_key, std::string act, std::string Del) {
		bool tmp = 0;
		for (int i = 0; i < m_key.t; i++) {
			if (s == m_key.actionAndButton[i].button) {
				Action[nnumberOfActions] = m_key.actionAndButton[i].DellAct;
				nnumberOfActions++;
				m_key.actionAndButton[i].act = act;
				m_key.actionAndButton[i].DellAct = Del;
				tmp = 1;
				i = m_key.t;
			}
		}
		if (tmp == 0) {
		
				m_key.NewAct(s, act, Del);
			
		}

	}

	void Count() {
		nnumberOfActions++;
	}

private:

	std::string Action[200];
	int nnumberOfActions = 0;
};



int main()
{
	setlocale(LC_ALL, "Russian");

	Keyboard Key;
	Workflow work;
	std::string a, b, c;
	a = "K";
	b = "print k";
	c = "del K";
	Key.NewAct(a,b,c);
	a = "C";
	b = "print C";
	c = "del C";
	Key.NewAct(a, b, c);
	Key.Help();
	std::cout << "Введите клавишу, которую ранее нажали" << std::endl;
	std::string s;
	std::cin >> s;
	std::cin >> a >> b;
	work.Reassignment(s, Key, a, b);
	Key.Help();
	work.Undo(Key);
	

}

