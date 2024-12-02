#pragma once

struct s_game_audio_settings {
    bool PushToTalk;
    char VoiceChatChannel;
    __int16 padding_1;
    float VoiceChatVolume;
    float un;
    char PrimaryUserPreferredInputDevice;
    uint8_t padding2;
    char VoiceChatInputDevice[256];
    char VoiceChatOutputDevice[256];
    char AudioOutputDevice[256];
    __int16 padding_2;
    float VoiceChatThreshold;
};

static_assert(sizeof(s_game_audio_settings) == 788);