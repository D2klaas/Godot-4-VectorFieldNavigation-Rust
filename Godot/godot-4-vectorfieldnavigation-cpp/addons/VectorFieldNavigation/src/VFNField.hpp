// Datei: src/VFNField.hpp
#pragma once
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>
#include <algorithm> // für std::find
#include <queue>
#include <limits>
#include "VFNMap.hpp"

namespace godot {

	class VFNMap; // <- Forward declaration
	class VFNPenaltyField; // <- Forward declaration

	class VFNField : public RefCounted {
		GDCLASS(VFNField, RefCounted)

	protected:
		static void _bind_methods();

	public:
		VFNField();
		~VFNField();

		void add_penalty_field( const Ref<VFNPenaltyField>& penalty_field );
		void remove_penalty_field( const Ref<VFNPenaltyField>& penalty_field );
		void add_target( int index );
		void clear_targets();
		void remove_target( int index );
		Dictionary calculate( );

	public: //things godot can change
		float max_effort;

	public:
		Ref<VFNMap> map;
		std::vector<int> targets;
		std::vector<int> open_list;
		std::vector<float> effort_map;
		std::vector<int> target_map;
		std::vector<Vector3> vector_map;
		std::vector<Ref<VFNPenaltyField>> penalty_fields;
		float highest_effort ;
	};

} // namespace godot
