#pragma once
#include <string>
#include <unordered_map>
class Response;
// an attack is a prompt where the player can choose an action
class Attack
{
public:
	std::string Text;
	std::unordered_map<std::string, Response> Responses;
	Response GetResponse(std::string playerAction);
	void Print();
	bool HasResponseFor(std::string action);

	Attack(const std::string& text) : Text(text) {}
};