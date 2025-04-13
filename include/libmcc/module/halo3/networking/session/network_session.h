#pragma once

namespace libmcc::halo3 {
	enum e_network_session_type : int {

	};

	enum e_network_session_class : int {
		_network_session_class_offline = 0x0,
		_network_session_class_system_link = 0x1,
		_network_session_class_xbox_live = 0x2,
		k_network_session_class_count = 0x3,
	};

	enum e_network_session_peer_state : int {
		_network_session_peer_state_none = 0x0,
		_network_session_peer_state_rejoining = 0x1,
		_network_session_peer_state_reserved = 0x2,
		_network_session_peer_state_disconnected = 0x3,
		_network_session_peer_state_connected = 0x4,
		_network_session_peer_state_joining = 0x5,
		_network_session_peer_state_joined = 0x6,
		_network_session_peer_state_waiting = 0x7,
		_network_session_peer_state_established = 0x8,
		k_network_session_peer_state_count = 0x9,
	};

	struct s_transport_unique_identifier {
		int part0;
		short part4[2];
	};

	struct s_transport_secure_address : s_transport_unique_identifier {
		char part8[8];
	};

	struct s_network_session_peer_connectivity {
		short peer_connectivity_mask;
		short peer_probe_mask;
		int peer_latency_min;
		int peer_latency_est;
		int peer_latency_max;
	};

	union s_network_session_peer {
		char __data[272];
	};

	static_assert(sizeof(s_network_session_peer) == 272);

	struct s_network_session_shared_membership {
	};

	class c_network_session_membership {
	public:
		class c_network_session* m_session; // 48
		s_network_session_shared_membership m_shared_network_membership; // 56
	};

	class c_network_channel_owner {
	public:
		virtual bool desire_channel_heartbeat(c_network_channel_owner*, int) = 0;
		virtual bool channel_is_load_bearing(c_network_channel_owner*, int) = 0;
		virtual bool attempt_channel_reconnection(c_network_channel_owner*, int, bool) = 0;
		virtual void notify_channel_connection(c_network_channel_owner*, int, int, bool) = 0;
		virtual void notify_channel_died(c_network_channel_owner*, int) = 0;
	};

	class c_network_session : public c_network_channel_owner {
	public:
		void* m_message_gateway;
		void* m_observer;
		void* m_session_manager;
		int m_session_index;
		e_network_session_type m_session_type;
		e_network_session_class m_session_class;
		c_network_session_membership m_session_membership;
	};
}
