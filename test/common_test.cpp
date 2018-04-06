#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include <ecsx/CompSparseStorage.h>
#include <ecsx/CompDenseStorage.h>
#include <ecsx/World.h>
#include <ecsx/Entity.h>
#include <ecsx/Component.h>
#include <ecsx/CompStorageType.h>

TEST_CASE("test sparse storage") {
	ecsx::detail::CompSparseStorage<int> storage;
	int i = 0;
	storage.Add(0, &i);
	i = 1;
	storage.Add(10, &i);
	REQUIRE(*static_cast<int*>(storage.Get(0)) == 0);
	REQUIRE(*static_cast<int*>(storage.Get(10)) == 1);
	REQUIRE(!storage.Get(5));
}

TEST_CASE("test dense storage") {
	ecsx::detail::CompDenseStorage<int> storage;
	int i = 0;
	storage.Add(0, &i);
	i = 1;
	storage.Add(10, &i);
	REQUIRE(*static_cast<int*>(storage.Get(0)) == 0);
	REQUIRE(*static_cast<int*>(storage.Get(10)) == 1);
}

struct Position : public ecsx::Component
{
	Position() : x(0), y(0) {}
	Position(float x, float y) : x(x), y(y) {}

	float x, y;
};

TEST_CASE("test component dense") {
	ecsx::World world;

	world.SetCompStorage<Position>(ecsx::detail::COMP_STORAGE_DENSE);

	auto e0 = world.CreateEntity();
	auto& comp = e0.AddComponent<Position>(1.0f, 2.0f);
	REQUIRE(Approx(comp.x) == 1.0f);
	REQUIRE(Approx(comp.y) == 2.0f);

	auto& comp1 = e0.GetComponent<Position>();
	REQUIRE(Approx(comp1.x) == 1.0f);
	REQUIRE(Approx(comp1.y) == 2.0f);
	
	comp1.x = 3;
	auto& comp2 = e0.GetComponent<Position>();
	REQUIRE(Approx(comp1.x) == 3.0f);
}

TEST_CASE("test component sparse") {
	ecsx::World world;

	world.SetCompStorage<Position>(ecsx::detail::COMP_STORAGE_SPARSE);

	auto e0 = world.CreateEntity();
	auto& comp = e0.AddComponent<Position>(1.0f, 2.0f);
	REQUIRE(Approx(comp.x) == 1.0f);
	REQUIRE(Approx(comp.y) == 2.0f);

	auto& comp1 = e0.GetComponent<Position>();
	REQUIRE(Approx(comp1.x) == 1.0f);
	REQUIRE(Approx(comp1.y) == 2.0f);

	comp1.x = 3;
	auto& comp2 = e0.GetComponent<Position>();
	REQUIRE(Approx(comp1.x) == 3.0f);
}