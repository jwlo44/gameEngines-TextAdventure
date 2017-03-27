#include "Attack.h"
#include "Enemy.h"
#include "IO.h"
#include "Response.h"
#include "assert.h"
void Attack::Print() const
{
	IO::PrintLn(Text);
	IO::PrintLn("Available Commands:\n");
	for (auto kvp : Responses)
	{
		IO::Print(kvp.first + ", ");
	}
	IO::PrintLn();
}

bool Attack::HasResponseFor(const std::string& action) const
{
	std::unordered_map<std::string, Response>::const_iterator found = Responses.find(action);
	if (found == Responses.end())
	{
		return false;
	}
	return true;
}

Response Attack::GetResponse(const std::string& action) const
{
	auto found = Responses.find(action);
	assert(found != Responses.end());
	return found->second;
}
