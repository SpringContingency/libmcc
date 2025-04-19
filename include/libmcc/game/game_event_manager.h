#pragma once

#include <Windows.h>

namespace libmcc {
	class i_game_event_manager {
	public:
		virtual bool AchievementEarned(
			const wchar_t* xuid,
			const GUID* guid,
			const wchar_t*,
			int
		) = 0;

		virtual bool AshesToAshes(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool Assist(
			const wchar_t* xuid,
			int,
			const GUID* guid,
			const wchar_t*,
			int,
			int,
			const GUID*,
			int,
			int,
			int,
			int,
			int,
			int,
			int,
			int,
			const wchar_t*,
			int,
			int,
			int,
			int
		) = 0;

		virtual bool AudioLogClaimed(
			const wchar_t* xuid,
			const GUID* guid,
			int
		) = 0;

		virtual bool Base(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual void Base(
			const wchar_t* xuid,
			int a3,
			const GUID* a4,
			const wchar_t* a5,
			int a6,
			int a7,
			const GUID* a8,
			int a9,
			int a10,
			int a11,
			int a12,
			int a13,
			int a14,
			int a15,
			int a16,
			const wchar_t* a17,
			int a18,
			int a19,
			int a20,
			int a21
		) = 0;

		virtual bool BIFactControllerSettings(
			const wchar_t* xuid,
			const GUID* guid,
			int a4,
			const wchar_t* a5,
			int a6,
			int a7,
			int a8
		) = 0;

		virtual bool BIFactDeepLink(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BIFactDeepLinkRecieve(
			const wchar_t* xuid,
			const GUID* guid,
			const wchar_t*,
			const wchar_t*
		) = 0;

		virtual bool BIFactDeepLinkSend(
			const wchar_t* xuid,
			const GUID* guid,
			const wchar_t*,
			const wchar_t*
		) = 0;

		virtual bool BIFactDualWield(
			const wchar_t* xuid,
			const GUID* guid,
			int,
			const wchar_t*,
			int,
			int,
			int,
			const void*
		) = 0;

		virtual bool BIFactGameSession(
			const wchar_t* a2,
			const GUID* a3,
			const void* a4,
			const void* a5,
			const wchar_t* a6,
			const void* a7,
			const void* a8,
			int a9,
			const wchar_t* a10,
			int a11,
			int a12,
			const void* a13,
			const wchar_t* a14,
			int a15,
			int a16,
			int a17,
			const void* a18,
			int a19,
			int a20,
			const void* a21,
			const void* a22,
			int a23,
			int a24,
			int a25,
			int a26,
			int a27,
			int a28,
			int a29
		) = 0;

		virtual bool BIFactLoadout(
			const wchar_t* xuid,
			const GUID* guid,
			int a4,
			const wchar_t* a5,
			int a6,
			int a7,
			int a8,
			int a9,
			int a10
		) = 0;

		virtual bool BIFactMatchmaking(
			const wchar_t* xuid,
			const GUID* guid,
			int a4,
			const wchar_t* a5,
			const void* a6,
			int a7,
			const void* a8,
			int a9,
			const void* a10,
			int a11,
			int a12,
			const GUID* a13
		) = 0;

		virtual bool BIFactMatchmakingDetails(
			const wchar_t* xuid,
			const GUID* guid,
			int a4,
			int a5,
			int a6,
			int a7,
			int a8,
			const void* a9,
			const void* a10,
			int a11,
			const wchar_t* a12,
			int a13,
			int a14,
			int a15,
			int a16
		) = 0;

		virtual bool BIFactMedia(
			const wchar_t* xuid,
			const GUID* guid,
			int a4,
			const wchar_t* a5,
			const void* a6,
			int a7,
			const void* a8,
			const wchar_t* a9
		) = 0;

		virtual bool BirdOfPrey(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BitsAndPiecesDestroyed(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		// Broadcasting

		virtual void BroadcastingAssist(
			const wchar_t* xuid,
			const GUID* guid,
			const void* a4,
			unsigned int a5
		) = 0;

		virtual void BroadcastingDeath(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingHeartbeat(
			const wchar_t* xuid,
			const GUID* guid,
			const void*
		) = 0;

		virtual bool BroadcastingKill(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingMatchEnd(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingMatchRoundEnd(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingMatchRoundStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingMatchStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingMedal(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingPlayerJoined(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingPlayerLeft(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool BroadcastingPlayerSpawn(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual void BroadcastingPlayerSwitchedTeams(
			const wchar_t* xuid,
			const GUID*,
			const FILETIME*,
			int index,
			int
		) = 0;

		virtual void BroadcastingScore(
			const wchar_t* xuid,
			const GUID*,
			int index,
			const FILETIME*,
			int,
			int,
			int,
			int
		) = 0;

		virtual bool BroadcastingStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool CampaignDifficulty(
			const wchar_t* xuid,
			const GUID* guid,
			const wchar_t*,
			const wchar_t*
		) = 0;
		
		virtual bool ChallengeCompleted(
			const wchar_t* xuid,
			const GUID* guid,
			const wchar_t*,
			int
		) = 0;
		
		virtual bool ClassicModeSwitched(
			const wchar_t* xuid,
			const GUID* guid,
			int
		) = 0;

		virtual bool CleverGirl(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;

		virtual bool ClueClaimed(
			const wchar_t* xuid,
			const GUID* guid,
			int
		) = 0;

		virtual bool CompletionCount(
			const wchar_t* xuid,
			const GUID* guid,
			int
		) = 0;

		virtual bool CoopMissionCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool CoopSpartanOpsMissionCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool Customization(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool DashboardContext(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool Death(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool DollFound(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool EliteWin(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool Emblem(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool EnemyDefeated(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool FriendsBestedOnHeroLeaderboard(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool GameProgress(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool GameVarSaved(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool GrenadeStick(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool HelloNurse(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool InGamePresence(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ISeeYou(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool Joinability(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool Lobby(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MainMenuPresence(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MapVarSaved(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MatchmakingHopper(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MediaUsage(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MeldOfferPresented(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MeldOfferResponded(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MeldPageAction(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MeldPageView(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MissionCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MortardomWraithsKilled(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MultiplayerGameEngine(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MultiplayerMap(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MultiplayerRoundEnd(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool MultiplayerRoundStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool NappersCaught(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool NewsStoryRead(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ObjectiveEnd(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ObjectiveStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PageAction(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PageView(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PhantomHunter(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PigsCanFly(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerCheckedInToday(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerDefeated(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerGameResults(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerGameResultsDamageStat(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerGameResultsGriefingStat(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerGameResultsGriefingStats(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerGameResultsInterestStats(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerGameResultsMedal(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerSessionEnd(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerSessionPause(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerSessionResume(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerSessionStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlayerSpawned(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlaylistCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool PlaylistProgress(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RankedStatsDNFInfo(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RankedStatsOverride(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RankedStatsPenalty(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RankedStatsUpdate(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RankedUpSpartanIv(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RealtimeFlagCaptured(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RealtimeMedal(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RealtimePilotedVehicle(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool RivalID(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SectionEnd(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SectionStart(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SectionStats(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SessionSizeUpdate(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SizeIsEverything(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SkeetShooter(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SkullClaimed(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SoloMissionCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SoloSpartanOpsMissionCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SpartanOpsMissionCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool Supercombine(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool SurvivalSpace(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool TerminalFound(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool TerminalId(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool TicketsEarned(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool TitleCompleted(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool TitleLaunched(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ValhallaSign(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ViewOffer(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool VIPStatusEarned(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool WhatAboutTanksDestroyed(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool WonWarGame(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ZanzibarSign(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool FirefightGameResults(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual bool ScavengerHuntObjectFound(
			const wchar_t* xuid,
			const GUID* guid
		) = 0;
		
		virtual void _() = 0;
		virtual void __() = 0;
		virtual void ___() = 0;
		virtual void ____() = 0;
		virtual void _____() = 0;
		virtual void ______() = 0;
		virtual void _______() = 0;
		virtual void ________() = 0;
		virtual void _________() = 0;
		virtual void __________() = 0;

		virtual int ___________() = 0;
		
		virtual void SetBoolTrue() = 0;
		virtual void SetBoolFalse() = 0;
		virtual bool GetBool() = 0;
		virtual void SetBool(bool, bool) = 0;
		virtual void MetaGameUpdateGameTicks(float game_ticks) = 0;
		virtual void GameResultUpdatePlayerTime(int player, float time) = 0;
		virtual void _____________(bool) = 0;
		virtual bool MetaGameGetFlags() = 0;
		virtual GUID* GetGUID() = 0;
		virtual void ______________(bool*) = 0;
		virtual void _______________() = 0;
		virtual void ________________() = 0;
	};

	struct i_game_event_manager_vftable {
		void* __data[151];
	};
}