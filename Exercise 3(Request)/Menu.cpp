#include "Menu.h"
#include <assert.h>

void Menu::run()
{
	MenuField outField;
	if (m_parent == nullptr)
	{
		MenuField outField("Quit", []() { break; });
	}
	else
	{
		MenuField outField("Back", [&]() { m_parent->run(); });
	}
	this->addMenuField(std::make_unique<MenuField>(outField));

	setName2centr();

	//����������� ������-������� ������ � ������������� ��������� ������

	while (true)
	{
		system("cls");
		std::cout << m_name << std::endl;
		for (int i(0); i < m_fields.size(); ++i)
		{
			std::cout << i << ". " << m_fields[i]->getName() << std::endl;
		}
		
		char choice;
		std::cin.clear();
		std::cin.ignore(1, '\n');
		std::cin >> choice;

		
		int index = choice - '0';
		if (index >= 0 && index < m_fields.size())
			m_fields[index]->execute();
		else
			std::cout << "Invalid choice." << std::endl;

	}
}

void Menu::addSubMenu(Menu &submenu)
{
	submenu.setParent(std::make_shared<Menu>(this));
	MenuField submenuField(submenu.m_name, []() {});
	submenuField.setAction([&]() { submenu.run(); });
	auto submenuFieldPtr{ std::make_unique<MenuField>(submenuField) };
	m_fields.push_back(submenuFieldPtr);
}

void Menu::setName2centr()
{
	if(m_fields.empty())
		return;

	size_t averageStr = 0;
	for (const auto &field : m_fields)
	{
		averageStr += field->getName().length();
	}
	averageStr /= m_fields.size();
	
	size_t countOfIndent = averageStr - m_name.length() / 2;

	m_name.insert(m_name.begin(), countOfIndent, '-');
	m_name.append(countOfIndent, '-');
}