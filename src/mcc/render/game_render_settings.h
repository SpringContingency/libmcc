#pragma once

struct s_game_render_settings_internal {
    union setting {
        struct {
            float scale;
            float offset;
        };
        float values[2];
    };

    char un;                                 // Offset: 0x08
    char TextureFilteringQuality;            // Offset: 0x09
    char LightingQuality;                    // Offset: 0x0A
    char EffectsQuality;                     // Offset: 0x0B
    char padding_2[1];                          // Unknown or padding
    char DetailsQuality;                     // Offset: 0x0D
    char PostProcessingQuality;              // Offset: 0x0E
    char WaterQuality;                       // Offset: 0x0F
    char padding_3[1];                          // Unknown or padding
    char AntiAliasing;                       // Offset: 0x11
    char MotionBlur;                         // Offset: 0x12
    char Blood;                              // Offset: 0x13
    char VSync;                              // Offset: 0x14
    char FPSLock;                            // Offset: 0x15
    char FidelityFXSuperResolution;          // Offset: 0x16
    char padding_4[161];                        // Unknown or padding
    char WaterLod;                           // Offset: 0xB8 (184)
    char padding_5[15];                         // Unknown or padding
    setting EffectsLODDistanceScale;            // Offset: 0xC8 (200)
    setting InstanceFadeModifier;               // Offset: 0xD0 (208)
    setting ObjectFadeModifier;                 // Offset: 0xD8 (216)
    setting ObjectDetailModifier;               // Offset: 0xE0 (224)
    setting ObjectImposterCutoffModifier;       // Offset: 0xE8 (232)
    setting DecalFadeDistanceScale;             // Offset: 0xF0 (240)
    setting StructureInstanceLODModifier;       // Offset: 0xF8 (248)
    setting CPUDynamicLightMaxCount;            // Offset: 0x100 (256)
    setting CPUDynamicLightScale;               // Offset: 0x108 (264)
    setting GPUDynamicLightMaxCount;            // Offset: 0x110 (272)
    setting GPUDynamicLightScale;               // Offset: 0x118 (280)
    setting ScreenspaceDynamicLightMaxCount;    // Offset: 0x120 (288)
    setting ScreenspaceDynamicLightScale;       // Offset: 0x128 (296)
    setting ShadowGenerateCount;                // Offset: 0x130 (304)
    setting ShadowQualityLOD;                   // Offset: 0x138 (312)
    __int64 padding_20;
    int DisableObjectPRT;                       // Offset: 0x140 (328)
    int DisableFirstPersonShadow;               // Offset: 0x14C (332)
    int DisableDynamicLightingShadows;          // Offset: 0x150 (336)
    int DisablePatchyFog;                       // Offset: 0x154 (340)
    int DisableCheapParticles;                  // Offset: 0x158 (344)
    int DisableSSAO;                            // Offset: 0x15C (348)
    char padding_21[16];                        // Unknown or padding
};

struct s_game_render_settings {
    void* render_buffer;
    s_game_render_settings_internal render_settings;
};

static_assert(sizeof(s_game_render_settings) == 0x170);

struct s_game_video_settings  {
    char padding_0[2];                                   // Unknown or padding
    char TextureResolution;                              // Offset: 0x02
    char ShadowQuality;                                  // Offset: 0x03
    char padding_1[4];                                   // Unknown or padding
    s_game_render_settings_internal RenderSettings;      // Offset: 0x08
};

static_assert(sizeof(s_game_video_settings) == 0x170);