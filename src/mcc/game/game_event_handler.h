#pragma once

#include <Windows.h>

class i_game_event_handler {
public:
    virtual bool AchievementEarned(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 AchievementID) = 0;
    virtual void AshesToAshes(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void Assist(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade) = 0;
    virtual void AudioLogClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 AudioLogID) = 0;
    virtual void Base(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void Betrayal(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade) = 0;
    virtual void BIFactControllerSettings(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 ControllerConfigurationID, bool LookInverted) = 0;
    virtual void BIFactDeepLink(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void BIFactDeepLinkRecieve(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL) = 0;
    virtual void BIFactDeepLinkSend(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL) = 0;
    virtual void BIFactDualWield(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 LeftWeaponID, INT32 RightWeaponID, FILETIME DualWieldTimeStamp) = 0;
    virtual void BIFactGameSession(LPWSTR UserID, GUID PlayerSessionID, FILETIME SessionStartTimeStamp, FILETIME SessionEndTimeStamp, LPWSTR HaloTitleID, FILETIME SubTitleStartTimeStamp, FILETIME SubTitleEndTimeStamp, INT32 GameCategoryID, LPWSTR LocaleID, INT32 MapID, INT32 ArmorID, UINT64 SkullsUsed, LPWSTR HopperID, INT32 PlayerCount, bool Matchmade, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, bool Won, UINT64 Score, UINT64 TeamScore, INT32 Standing, bool FirstPlace, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 Betrayals, INT32 Suicides) = 0;
    virtual void BIFactLoadout(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 PrimaryWeaponID, INT32 SecondaryWeaponID, INT32 GrenadeID, INT32 ShieldID) = 0;
    virtual void BIFactMatchmaking(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR LobbyID, FILETIME LobbyEntryTimeStamp, bool JoinedMatch, FILETIME JoinMatchTimeStamp, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, INT32 PartySize, GUID PartyID) = 0;
    virtual void BIFactMatchmakingDetails(LPWSTR UserID, GUID PlayerSessionID, INT32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, FILETIME LobbyEntryTimeStamp, FILETIME LobbyExitTimeStamp, INT32 ExitReason, LPWSTR GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, INT32 NumPlayers, INT32 NumPreserveSessionTicketsCreated) = 0;
    virtual void BIFactMedia(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, FILETIME MediaStartTimeStamp, bool WasSkipped, FILETIME MediaSkipTimeStamp, LPWSTR MediaID) = 0;
    virtual void BirdOfPrey(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void BitsAndPiecesDestroyed(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void BroadcastingAssist(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 CurrentAssists) = 0;
    virtual void BroadcastingDeath(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentDeaths) = 0;
    virtual void BroadcastingHeartbeat(LPWSTR UserID, GUID PlayerSessionID, INT64 Heartbeat) = 0;
    virtual void BroadcastingKill(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentKills) = 0;
    virtual void BroadcastingMatchEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp) = 0;
    virtual void BroadcastingMatchRoundEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp) = 0;
    virtual void BroadcastingMatchRoundStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 RoundNumber) = 0;
    virtual void BroadcastingMatchStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MapVariantID, INT32 GameVariantID, LPWSTR PlaylistID) = 0;
    virtual void BroadcastingMedal(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MedalID) = 0;
    virtual void BroadcastingPlayerJoined(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID) = 0;
    virtual void BroadcastingPlayerLeft(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp) = 0;
    virtual void BroadcastingPlayerSpawn(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp) = 0;
    virtual void BroadcastingPlayerSwitchedTeams(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID, LPWSTR WebColor) = 0;
    virtual void BroadcastingScore(LPWSTR UserID, GUID PlayerSessionID, INT32 ControllerIndex, FILETIME Timestamp, INT32 CurrentRoundScore, INT32 CurrentTotalScore, INT32 CurrentRoundTeamScore, INT32 CurrentTotalTeamScore) = 0;
    virtual void BroadcastingStart(LPWSTR UserID, GUID PlayerSessionID, UINT32 GameType, UINT32 Map, UINT32 TopPlayerRank, LPWSTR PlayerIDs, GUID MatchID, bool PlayerIsCaster, INT64 MatchStartTime) = 0;
    virtual void CampaignDifficulty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR CampaignDifficulty) = 0;
    virtual void ChallengeCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 ChallengeID) = 0;
    virtual void ClassicModeSwitched(LPWSTR UserID, GUID PlayerSessionID, INT32 MapID) = 0;
    virtual void CleverGirl(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void ClueClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 ClueID) = 0;
    virtual void CoopMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MissionID, INT32 MapID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, INT32 DifficultyID) = 0;
    virtual void CoopSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID) = 0;
    virtual void CompletionCount(LPWSTR UserID, GUID PlayerSessionID, INT32 Count) = 0;
    virtual void Customization(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2, LPWSTR ServiceID, LPWSTR ClanID, INT32 AvatarID, INT32 NameplateID) = 0;
    virtual void DashboardContext(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DashboardContext) = 0;
    virtual void Death(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot) = 0;
    virtual void DollFound(LPWSTR UserID, GUID PlayerSessionID, INT32 DollID) = 0;
    virtual void EliteWin(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade) = 0;
    virtual void Emblem(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2) = 0;
    virtual void EnemyDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot) = 0;
    virtual void FriendsBestedOnHeroLeaderboard(LPWSTR UserID, GUID PlayerSessionID, INT32 LeaderboardID, INT32 LeaderboardRows) = 0;
    virtual void GameProgress(LPWSTR UserID, GUID PlayerSessionID, float CompletionPercent) = 0;
    virtual void GameVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseGameCategory, LPWSTR GameVarName) = 0;
    virtual void GrenadeStick(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID) = 0;
    virtual void HelloNurse(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void InGamePresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitle, INT32 CampaignDifficulty, INT32 MultiplayerMap) = 0;
    virtual void ISeeYou(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void Joinability(LPWSTR UserID, GUID PlayerSessionID, bool InGame) = 0;
    virtual void Lobby(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR Lobby) = 0;
    virtual void MainMenuPresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MainMenuPresence) = 0;
    virtual void MapVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseMapID, LPWSTR MapVarName) = 0;
    virtual void MatchmakingHopper(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MatchmakingHopper) = 0;
    virtual void MediaUsage(LPWSTR AppSessionID, LPWSTR AppSessionStartDateTime, UINT32 UserIDType, LPWSTR UserID, LPWSTR SubscriptionTierType, LPWSTR SubscriptionTier, LPWSTR MediaType, LPWSTR ProviderID, LPWSTR ProviderMediaID, LPWSTR ProviderMediaInstanceID, GUID BingID, UINT64 MediaLengthMs, UINT32 MediaControlAction, float PlaybackSpeed, UINT64 MediaPositionMs, UINT64 PlaybackDurationMs, LPWSTR AcquisitionType, LPWSTR AcquisitionContext, LPWSTR AcquisitionContextType, LPWSTR AcquisitionContextID, INT32 PlaybackIsStream, INT32 PlaybackIsTethered, LPWSTR MarketplaceLocation, LPWSTR ContentLocale, float TimeZoneOffset, UINT32 ScreenState) = 0;
    virtual void MeldOfferPresented(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, LPWSTR Page, INT32 SourceTileIndex) = 0;
    virtual void MeldOfferResponded(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, INT32 UpsellOutcome) = 0;
    virtual void MeldPageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content, INT32 SourceTileIndex, INT32 SourceTileX, INT32 SourceTileY, INT32 SourceTileWidth, INT32 SourceTileHeight) = 0;
    virtual void MeldPageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content, LPWSTR FilterContext, INT32 FilterDirection) = 0;
    virtual void MissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, bool Coop, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, INT32 DifficultyID, UINT64 MissionScore64, UINT64 SkullUsedFlags, INT32 NumPlayers, LPWSTR PlayerSectionStats, INT32 Kills, float Multiplier, INT32 Penalties, float SkullMultiplier, INT32 TotalSoloMissionsComplete, INT32 TotalCoopMissionsComplete) = 0;
    virtual void MortardomWraithsKilled(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void MultiplayerGameEngine(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerGameEngine) = 0;
    virtual void MultiplayerMap(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerMap) = 0;
    virtual void MultiplayerRoundEnd(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID, float TimeInSeconds, INT32 ExitStatusID) = 0;
    virtual void MultiplayerRoundStart(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID) = 0;
    virtual void NappersCaught(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void NewsStoryRead(LPWSTR UserID, GUID PlayerSessionID, LPWSTR StoryID) = 0;
    virtual void ObjectiveEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID, INT32 ExitStatusID) = 0;
    virtual void ObjectiveStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID) = 0;
    virtual void PageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content) = 0;
    virtual void PageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content) = 0;
    virtual void PhantomHunter(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void PigsCanFly(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void PlayerCheckedInToday(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID) = 0;
    virtual void PlayerDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 EnemyWeaponID, float LocationX, float LocationY, float LocationZ) = 0;
    virtual void PlayerGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 GameIndexByCategory, INT32 GameIndexByTitle, INT32 GameIndexByTitleCategory, INT32 MapID, INT32 GameCategoryID, bool MatchMade, bool Won, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, UINT64 Score64, INT32 Standing, bool FirstPlace, INT32 MedalCount, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 HeadShots, INT32 MostKillsInARow, LPWSTR CustomStat1ID, INT32 CustomStat1, LPWSTR CustomStat2ID, INT32 CustomStat2, LPWSTR CustomStat3ID, INT32 CustomStat3, LPWSTR CustomStat4ID, INT32 CustomStat4, GUID MatchID) = 0;
    virtual void PlayerGameResultsDamageStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 DamageReportingType, INT32 DamageStatisticType, INT32 DamageCount, INT32 GameCategoryID) = 0;
    virtual void PlayerGameResultsGriefingStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty) = 0;
    virtual void PlayerGameResultsGriefingStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty) = 0;
    virtual void PlayerGameResultsInterestStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 OrdnanceDrops, INT32 OrdnanceStrikes, UINT64 TimeMSDriven, INT32 UnitsDriven, UINT64 TimeMSPiloted, INT32 UnitsPiloted, UINT64 TimeMSPassenger, INT32 UnitsMovedPassenger, UINT64 TimeMSOnFoot, INT32 UnitsMovedOnFoot, INT32 DriverAssists, INT32 ArmorAbilityUseJetpack, INT32 ArmorAbilityUseHologram, INT32 ArmorAbilityUseReflectiveShield, INT32 ArmorAbilityUseActiveCamo, INT32 ArmorAbilityUseThrusterPack, INT32 ArmorAbilityUseAutoTurret, INT32 ArmorAbilityUseXRay) = 0;
    virtual void PlayerGameResultsMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 MedalType, INT32 MedalCount) = 0;
    virtual void PlayerSessionEnd(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID) = 0;
    virtual void PlayerSessionPause(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID) = 0;
    virtual void PlayerSessionResume(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID) = 0;
    virtual void PlayerSessionStart(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID) = 0;
    virtual void PlayerSpawned(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, float LocationX, float LocationY, float LocationZ) = 0;
    virtual void PlaylistCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, UINT32 PlaylistID, UINT64 Score64, UINT64 TimeMS, INT32 Penalties, LPWSTR MissionStats, bool IsCoop) = 0;
    virtual void PlaylistProgress(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 PlaylistID, INT32 NumMapsCompleted, UINT64 Score64, bool IsCoop, INT32 NumPlayers, bool ShouldPostTime, UINT64 TotalPlayListTimeMS) = 0;
    virtual void RankedStatsDNFInfo(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double FinishesOverStarts, INT32 FinishesMinusStarts, INT32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts) = 0;
    virtual void RankedStatsOverride(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked) = 0;
    virtual void RankedStatsPenalty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, INT32 NumPenaltiesApplied) = 0;
    virtual void RankedStatsUpdate(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked, bool PenaltyApplied) = 0;
    virtual void RankedUpSpartanIv(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SpartanIvRank, INT32 SpecialisationType) = 0;
    virtual void RealtimeFlagCaptured(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade) = 0;
    virtual void RealtimeMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, INT32 GameMode, bool MatchMade, INT32 MedalType, INT32 MedalCount) = 0;
    virtual void RealtimePilotedVehicle(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade, INT32 VehicleID, UINT64 TimeMS, INT32 Distance) = 0;
    virtual void RivalID(LPWSTR UserID, GUID PlayerSessionID, INT64 RivalID) = 0;
    virtual void SectionEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID, INT32 MissionID) = 0;
    virtual void SectionStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 MissionID) = 0;
    virtual void SectionStats(LPWSTR UserID, GUID PlayerSessionID, INT32 MissionID, INT32 SectionID, INT32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds) = 0;
    virtual void SessionSizeUpdate(LPWSTR UserID, GUID PlayerSessionID, INT32 SessionSize, INT32 SessionSizeMax) = 0;
    virtual void SizeIsEverything(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void SkeetShooter(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void SkullClaimed(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID) = 0;
    virtual void SoloMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed) = 0;
    virtual void SoloSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID) = 0;
    virtual void SpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 MissionID, INT32 DifficultyID, bool IsCoop) = 0;
    virtual void Supercombine(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID) = 0;
    virtual void SurvivalSpace(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR SurvivalSpace) = 0;
    virtual void TerminalFound(LPWSTR UserID, GUID PlayerSessionID, INT32 TerminalID) = 0;
    virtual void TerminalID(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID) = 0;
    virtual void TicketsEarned(LPWSTR UserID, GUID PlayerSessionID, INT32 TicketCount) = 0;
    virtual void TitleCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID) = 0;
    virtual void TitleLaunched(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID) = 0;
    virtual void ValhallaSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID) = 0;
    virtual void ViewOffer(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid) = 0;
    virtual void VIPStatusEarned(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void WhatAboutTanksDestroyed(LPWSTR UserID, GUID PlayerSessionID) = 0;
    virtual void WonWarGame(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID) = 0;
    virtual void ZanzibarSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID) = 0;
    virtual void FirefightGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade, UINT64 TimePlayedMS, UINT32 Kills, UINT32 MostKillsInARow, UINT32 SetsCompleted, UINT32 WavesCompleted, UINT32 GeneratorsDestroyed) = 0;
    virtual void sub_140440A88(__int64 a2, wchar_t* a3, __int64 a4, int a5, int a6) = 0;
    virtual void unused_00() {};
    virtual void unused_01() {};
    virtual void unused_02() {};
    virtual void unused_03() {};
    virtual void unused_04() {};
    virtual void unused_05() {};
    virtual void unused_06() {};
    virtual void unused_07() {};
    virtual void unused_08() {};
    virtual void unused_09() {};
    virtual int unused_10() {return 0;};
    virtual void CinematicStart() = 0;
    virtual void CinematicEnd() = 0;
    virtual bool InCinematic() = 0;
    virtual void ChudShow(int a2, bool value) = 0;
    virtual void SetTickLength(float tick_length) = 0;
    virtual void unused_11() {};
    virtual void CampaignCarnageReport(bool a2) = 0;
    virtual bool MetaGameGetValue() = 0;
    virtual void* unknown_01() = 0;
    virtual void* unknown_02() = 0;
    virtual void unknown_03() = 0;
    virtual void unknown_04() = 0;
};