#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/listbox.hpp>
#include "HighScore.h"


using namespace nana;
using namespace hsc;
int main()
{

	// form to hold everything
	form fm;
	HighScore * hs = new HighScore();
	hs->addScore(100, "juan");
	hs->addScore(150, "pepe");
	hs->addScore(200, "carlos");
	hs->addScore(250, "matias");
	hs->addScore(300, "lisandro");

	hs->getScore();
	hs->getName();

	list<int>* lista1;
	lista1 = hs->getScore();
	list<string>* lista2;
	lista2 = hs->getName();
	list<int>::iterator it;
	list<string>::iterator it2;
	// listbox to be the property grid
	listbox lb(fm, nana::rectangle(10, 10, 280, 100));

	// column headers
	lb.append_header("Name", 200);
	lb.append_header("Score", 200);
	it2 = lista2->begin();
	for (it = lista1->begin(); it != lista1->end(); it++ )
	{
		string caster = to_string(*it);
		lb.at(0).append({*it2 ,caster});
		it2++;
	}
	// add two items to the default category
	//lb.at(0).append({ "A", "0" });
	//lb.at(0).append({ "B", "0" });
	//lb.at(0).append({ "C", "0" });
	//lb.at(0).append({ "D", "0" });
	//lb.at(0).append({ "E", "0" });
	


	fm.show();
	exec();
}