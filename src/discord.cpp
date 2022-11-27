#include "discord.h"

#include <time.h>
#include <chrono>

#include <discord_rpc.h>
#include <discord_register.h>
#include "skCrypt.h"

static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void Discord::init()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize(skCrypt("984141600395493427"), &Handle, 1, NULL);
}

void Discord::update()
{
	static std::string  state(skCrypt("https://discord.gg/easyvictory"));
	static std::string  details(skCrypt("Premium user"));
	static std::string  largeImageKey(skCrypt("icon3"));
	static std::string  largeImageText(skCrypt("Easy victory"));
	static std::string  smallImageKey(skCrypt("icon3"));
	DiscordRichPresence discordPresence;

	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state          = state.c_str();
	discordPresence.details        = details.c_str();
	discordPresence.startTimestamp = eptime;
	discordPresence.largeImageKey  = largeImageKey.c_str();
	discordPresence.largeImageText = largeImageText.c_str();
	discordPresence.smallImageKey  = smallImageKey.c_str();
	Discord_UpdatePresence(&discordPresence);
}