#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include <entity0/CompSparseStorage.h>
#include <entity0/CompDenseStorage.h>
#include <entity0/World.h>
#include <entity0/Entity.h>
#include <entity0/Component.h>
#include <entity0/CompStorageType.h>

TEST_CASE("test sparse storage") {
	e0::detail::CompSparseStorage<int> storage;
	int i = 0;
	storage.PushBack(0, &i);
	i = 1;
	storage.PushBack(10, &i);
	REQUIRE(*static_cast<int*>(storage.Get(0)) == 0);
	REQUIRE(*static_cast<int*>(storage.Get(10)) == 1);
	REQUIRE(!storage.Get(5));
}

TEST_CASE("test dense storage") {
	e0::detail::CompDenseStorage<int> storage;
	int i = 0;
	storage.PushBack(0, &i);
	i = 1;
	storage.PushBack(10, &i);
	REQUIRE(*static_cast<int*>(storage.Get(0)) == 0);
	REQUIRE(*static_cast<int*>(storage.Get(10)) == 1);
}

struct Position : public e0::Component
{
	Position() : x(0), y(0) {}
	Position(float x, float y) : x(x), y(y) {}

	float x, y;
};

TEST_CASE("test component dense") {
	e0::World world;

	world.SetCompStorage<Position>(e0::COMP_STORAGE_DENSE);

	auto e0 = world.CreateEntity();
	auto& comp = world.AddComponent<Position>(e0, 1.0f, 2.0f);
	REQUIRE(Approx(comp.x) == 1.0f);
	REQUIRE(Approx(comp.y) == 2.0f);

	auto& comp1 = world.GetComponent<Position>(e0);
	REQUIRE(Approx(comp1.x) == 1.0f);
	REQUIRE(Approx(comp1.y) == 2.0f);

	comp1.x = 3;
	auto& comp2 = world.GetComponent<Position>(e0);
	REQUIRE(Approx(comp1.x) == 3.0f);
}

TEST_CASE("test component sparse") {
	e0::World world;

	world.SetCompStorage<Position>(e0::COMP_STORAGE_SPARSE);

	auto e0 = world.CreateEntity();
	auto& comp = world.AddComponent<Position>(e0, 1.0f, 2.0f);
	REQUIRE(Approx(comp.x) == 1.0f);
	REQUIRE(Approx(comp.y) == 2.0f);

	auto& comp1 = world.GetComponent<Position>(e0);
	REQUIRE(Approx(comp1.x) == 1.0f);
	REQUIRE(Approx(comp1.y) == 2.0f);

	comp1.x = 3;
	auto& comp2 = world.GetComponent<Position>(e0);
	REQUIRE(Approx(comp1.x) == 3.0f);
}