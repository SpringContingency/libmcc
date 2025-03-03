#pragma once

#include "observer.h"

namespace libmcc::halo3 {
	enum e_camera_mode : uint32_t {
		_camera_mode_following = 0x0,
		_camera_mode_orbiting = 0x1,
		_camera_mode_flying = 0x2,
		_camera_mode_first_person = 0x3,
		_camera_mode_dead = 0x4,
		_camera_mode_static = 0x5,
		_camera_mode_scripted = 0x6,
		_camera_mode_authored = 0x7,

		k_number_of_camera_modes = 0x8,
		k_camera_mode_null = 0xFFFFFFFF,
	};

	class c_camera {
	public:
		virtual int get_type();
		virtual int get_perspective();
		virtual void update(int, float, s_observer_command*);
		virtual int get_target();
		virtual void set_target(int);
		virtual void set_position(const real_point3d*);
		virtual void set_forward(const real_vector3d*);
		virtual void set_roll(float);
		virtual void enable_orientation(bool);
		virtual void enable_movement(bool);
		virtual void enable_roll(bool);
		virtual void handle_deleted_player(int);
		virtual void handle_deleted_object(int);
	public:
		int m_object_index;
		int m_flags;
		int : 32;
	};

	class c_following_camera : public c_camera {
	public:
		
	};

	class c_orbiting_camera : public c_camera {
	public:
		real_euler_angles2d m_facing;
		real m_distance;
		real m_z_offset;
	};

	class c_flying_camera : public c_camera {
	public:
		real_point3d m_position;
		real_euler_angles2d m_facing;
		real m_roll;
	};

	class c_first_person_camera : public c_camera {
	public:
		real m_field_of_view;
		real_euler_angles2d m_facing;
	};

	class c_dead_camera : public c_camera {
	public:
		real_point3d m_position;
		real_euler_angles2d m_orientation;
		real m_focus_distance;
		real m_field_of_view;
	};

	class c_static_camera : public c_camera {
	public:
		real_point3d m_position;
		real_vector3d m_forward;
		real m_field_of_view;
	};

	class c_scripted_camera : public c_camera {

	};

	class c_authored_camera : public c_camera {

	};

	union c_camera_storage {
		c_camera camera;
		c_following_camera following_camera;
		c_orbiting_camera orbiting_camera;
		c_flying_camera flying_camera;
		c_first_person_camera first_person_camera;
		c_dead_camera dead_camera;
		c_static_camera static_camera;
		c_scripted_camera scripted_camera;
		c_authored_camera authored_camera;
		char camera_data[92];
	};
}
