#include <iostream>
#include <dpp/dpp.h>

std::string getBotToken() {
    return getenv("LUCID_RIFT_DISCORD_BOT_TOKEN");
}

int main() {
    const auto token = getBotToken();
    printf("Detected bot token:\n-- Length: %lu\n-- Data: %s\n", token.length(), token.c_str());

    printf("Connecting to discord bot API server.\n");
    printf("-- Creating bot instance\n");

    dpp::cluster service(token);

    service.on_log([](const dpp::log_t &event) {
        printf("Log event: %s\n", event.message.c_str());
    });

    service.on_slashcommand([&service] (const dpp::slashcommand_t &cx) {
        if (cx.command.get_command_name() == "ping") {
            cx.reply("DX Engine Ping Detected: " + std::to_string(service.rest_ping));
        }
    });

    service.on_ready([&service](const dpp::ready_t &event) {
        printf("-- Applying slash commands\n");

        // Ping command
        dpp::slashcommand pingCmd("ping", "Check the internal ping state", service.me.id);

        // Register
        service.global_command_create(pingCmd);

        printf("-- Bot connected as user: '%s'\n", "LucidRift");
    });

    printf("-- Attempting to connect to server\n");
    service.start(dpp::st_wait);

    return 0;
}
