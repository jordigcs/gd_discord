#ifndef GDDISCORD_CLASS_H
#define GDDISCORD_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/node2D.hpp>

#include <godot_cpp/core/binder_common.hpp>

#include "../game_sdk_cpp/discord.h"

using namespace godot;

class Discord : public Node2D {
	GDCLASS(Discord, Node2D);

protected:
	static void _bind_methods();
	bool initialized = false;

private:
	discord::Core* core{};

public:
	Discord();
	~Discord();
	void init(discord::ClientId id, int create_flag);
};

#endif // ! GDDISCORD_CLASS_H
