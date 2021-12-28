
#include "gd_discord.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <string>
using namespace godot;

void Discord::_bind_methods() {
	ClassDB::bind_method(D_METHOD("init", "id", "create_flag"), &Discord::init);
}

Discord::Discord() {
}

Discord::~Discord()
{
}

void Discord::init(discord::ClientId id, int create_flag) {
	if(!initialized) {
		discord::Result r = discord::Core::Create(id, create_flag, &core);
		if (r != discord::Result::Ok) {
			initialized = false;
			UtilityFunctions::print("Discord failed to initialize.", static_cast<int>(r));
		}
		else {
			initialized = true;
			UtilityFunctions::print("Discord initialized.");
		}
	}
}