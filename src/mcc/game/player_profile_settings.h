#pragma once

#include <array>

typedef unsigned int t_user_customization_item;

extern std::array<const char*, 2131> g_user_customization_item_names;
inline const std::array<const char*, 2131>* user_customization_item_names() { return &g_user_customization_item_names; }
inline const char* user_customization_item_names(t_user_customization_item item) { return g_user_customization_item_names[item]; }

struct s_player_profile_settings {
    bool SubtitleSetting; // 0x0
    bool SubtitleSizeSetting; // 0x1
    bool SubtitleBackgroundSetting; // 0x2
    bool SubtitleShadowColorSetting; // 0x3
    bool DialogueColorStyleSetting; // 0x4
    bool DialogueColorSetting; // 0x5
    bool DialoguePaletteSetting; // 0x6
    bool SpeakerSetting; // 0x7
    bool SpeakerColorStyleSetting; // 0x8
    bool SpeakerColorSetting; // 0x9
    bool SpeakerPaletteSetting; // 0xA
    bool SubtitleFontSetting; // 0xB
    float SubtitleBackgroundOpacitySetting; // 0xC
    float SubtitleShadowOpacitySetting; // 0x10
    int FOVSetting; // 0x14
    int VehicleFOVSetting; // 0x18
    bool CrosshairLocation; // 0x1C
    bool LookControlsInverted; // 0x1D
    bool MouseLookControlsInverted; // 0x1E
    bool VibrationDisabled; // 0x1F
    bool ImpulseTriggersDisabled; // 0x20
    bool AircraftControlsInverted; // 0x21
    bool MouseAircraftControlsInverted; // 0x22
    bool AutoCenterEnabled; // 0x23
    bool CrouchLockEnabled; // 0x24
    bool MKCrouchLockEnabled; // 0x25
    bool ClenchProtectionEnabled; // 0x26
    bool UseFemaleVoice; // 0x27
    int HoldToZoom; // 0x28
    int PlayerModelPrimaryColorIndex; // 0x2C
    int PlayerModelSecondaryColorIndex; // 0x30
    int PlayerModelTertiaryColorIndex; // 0x34
    bool UseEliteModel; // 0x38
    bool LockMaxAspectRatio; // 0x39
    bool un; // 0x3A
    bool UsersSkinsEnabled; // 0x3B
    int PlayerModelPermutation; // 0x3C
    t_user_customization_item HelmetIndex; // 0x40
    t_user_customization_item LeftShoulderIndex; // 0x44
    t_user_customization_item RightShoulderIndex; // 0x48
    t_user_customization_item ChestIndex; // 0x4C
    t_user_customization_item WristIndex; // 0x50
    t_user_customization_item UtilityIndex; // 0x54
    t_user_customization_item ArmsIndex; // 0x58
    t_user_customization_item LegsIndex; // 0x5C
    t_user_customization_item BackpackIndex; // 0x60
    t_user_customization_item SpartanBodyIndex; // 0x64
    t_user_customization_item SpartanArmorEffectIndex; // 0x68
    t_user_customization_item KneesIndex; // 0x6C
    t_user_customization_item VisorColorIndex; // 0x70
    t_user_customization_item EliteHelmetIndex; // 0x74
    t_user_customization_item EliteLeftShoulderIndex; // 0x78
    t_user_customization_item EliteRightShoulderIndex; // 0x7C
    t_user_customization_item EliteChestIndex; // 0x80
    t_user_customization_item EliteArmsIndex; // 0x84
    t_user_customization_item EliteLegsIndex; // 0x88
    t_user_customization_item EliteArmorIndex; // 0x8C
    t_user_customization_item EliteArmorEffectIndex; // 0x90
    t_user_customization_item VoiceIndex; // 0x94
    t_user_customization_item PlayerModelPrimaryColor; // 0x98
    t_user_customization_item PlayerModelSecondaryColor; // 0x9C
    t_user_customization_item PlayerModelTertiaryColor; // 0xA0
    t_user_customization_item SpartanPose; // 0xA4
    t_user_customization_item ElitePose; // 0xA8
    struct Skin_t { int object; t_user_customization_item skin; } Skins[32]; // 0xAC
    wchar_t ServiceTag[4]; // 0x1AC
    bool OnlineMedalFlasher; // 0x1B4
    bool VerticalLookSensitivity; // 0x1B5
    bool HorizontalLookSensitivity; // 0x1B6
    bool LookAcceleration; // 0x1B7
    float LookAxialDeadZone; // 0x1B8
    float LookRadialDeadZone; // 0x1BC
    float ZoomLookSensitivityMultiplier; // 0x1C0
    float VehicleLookSensitivityMultiplier; // 0x1C4
    bool ButtonPreset; // 0x1C8
    bool StickPreset; // 0x1C9
    bool LeftyToggle; // 0x1CA
    bool FlyingCameraTurnSensitivity; // 0x1CB
    bool FlyingCameraPanning; // 0x1CC
    bool FlyingCameraSpeed; // 0x1CD
    bool FlyingCameraThrust; // 0x1CE
    bool TheaterTurnSensitivity; // 0x1CF
    bool TheaterPanning; // 0x1D0
    bool TheaterSpeed; // 0x1D1
    bool TheaterThrust; // 0x1D2
    bool MKTheaterTurnSensitivity; // 0x1D3
    bool MKTheaterPanning; // 0x1D4
    bool MKTheaterSpeed; // 0x1D5
    bool MKTheaterThrust; // 0x1D6
    bool SwapTriggersAndBumpers; // 0x1D7
    bool UseModernAimControl; // 0x1D8
    bool UseDoublePressJumpToJetpack; // 0x1D9
    bool DualWieldInverted; // 0x1DA
    bool ControllerDualWieldInverted; // 0x1DB
    bool ControllerHornetControlJoystick; // 0x1DC
    bool ControllerBansheeTrickButtonsSwapped; // 0x1DD
    bool ColorCorrection; // 0x1DE
    bool EnemyPlayerNameColor; // 0x1DF
    int GameEngineTimer; // 0x1E0

    struct LoadoutSlot_t {
        int TacticalPackageIndex;
        int SupportUpgradeIndex;
        int PrimaryWeaponIndex;
        int SecondaryWeaponIndex;
        int PrimaryWeaponVariantIndex;
        int SecondaryWeaponVariantIndex;
        int EquipmentIndex;
        int GrenadeIndex;
        wchar_t Name[14];
    } LoadoutSlots[5]; // 0x1E4

    char GameSpecific[0x100]; // 0x310
    float MouseSensitivity; // 0x410
    bool MouseSmoothing; // 0x414
    bool MouseAcceleration; // 0x415
    __int16 PixelPerfectHudScale; // 0x416
    float MouseAccelerationMinRate; // 0x418
    float MouseAccelerationMaxAccel; // 0x41C
    float MouseAccelerationScale; // 0x420
    float MouseAccelerationExp; // 0x424
    int KeyboardMouseButtonPreset; //? 0x428

    struct CustomKeyboardMouseMappingV2_t {
        int AbstractButton;
        int VirtualKeyCodes[5];
    } CustomKeyboardMouseMappingV2[66]; // 0x42C

    float MasterVolume; // [0.0, 1.0] 0xA5C
    float MusicVolume; // [0.0, 1.0] 0xA60
    float SfxVolume; // [0.0, 1.0] 0xA64

    char buffer4[0xC]; // 0xA68

    float Brightness; // 0xA74

    struct WeaponDisplayOffset_T {
        float x,y,z;
    } WeaponDisplayOffset[5]; // 0xA78

    int ColorBlindMode; // 0xAB4
    int ColorBlindStrength; // 0xAB8
    int ColorBlindBrightness; // 0xABC
    int ColorBlindContrast; // 0xAC0
    int RemasteredHUDSetting; // 0xAC4
    float HUDScale; // 0xAC8
};

static_assert(sizeof(s_player_profile_settings) == 0xACC);