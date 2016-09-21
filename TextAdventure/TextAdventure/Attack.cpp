#include "Attack.h"
#include "Enemy.h"
#include "IO.h"
#include "Response.h"
void Attack::Print()
{
	IO::PrintLn(Text);
	IO::PrintLn("Available Commands:\n");
	for (auto kvp : Responses)
	{
		IO::Print(kvp.first + "\t");
	}
	IO::PrintLn();
}

bool Attack::HasResponseFor(std::string action)
{
	std::unordered_map<std::string, Response>::const_iterator found = Responses.find(action);
	if (found == Responses.end())
	{
		return false;
	}
	return true;
}

Response Attack::GetResponse(std::string action)
{
	return Responses[action];
}
