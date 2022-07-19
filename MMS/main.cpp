#include "mms.h"
#include "utilities.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

void run_tests(MMS &mms) {
  assert(("Number of animals in the inventory is incorrect.",
          3 == mms.inventorySizeByType()));
  assert(("Number of turtles in the inventory is incorrect.",
          1 == mms.inventorySizeByType(TURTLE)));
  assert(("Number of cats in the inventory is incorrect.",
          1 == mms.inventorySizeByType(CAT)));
  assert(("Number of dogs in the inventory is incorrect.",
          1 == mms.inventorySizeByType(DOG)));
  assert(("Number of animals with shots in the inventory is incorrect.",
          2 == mms.inventorySizeByShots(true)));
  assert(("Number of animals without shots in the inventory is incorrect.",
          1 == mms.inventorySizeByShots(false)));
  assert(("Number of animals with restrictions in the inventory is incorrect.",
          1 == mms.inventorySizeByRestrictions(true)));
  assert(
      ("Number of animals without restrictions in the inventory is incorrect.",
       2 == mms.inventorySizeByRestrictions(false)));

  assert(("No animal named Tommy Tootone in the inventory.",
          contains(std::string{"Tommy Tootone"}, mms.animalsInInventory())));
  assert(("No animal named Kitty Genevese in the inventory.",
          contains(std::string{"Kitty Genevese"}, mms.animalsInInventory())));
  assert(("No animal named Grand Paw in the inventory.",
          contains(std::string{"Grand Paw"}, mms.animalsInInventory())));
}

int main() {
  std::string inventory_filename{"inventory.txt"};
  std::ifstream inventory{inventory_filename, std::ios_base::binary};
  assert(("Could not open the inventory file.", inventory.is_open()));

  MMS mangerManagementSystem{};
  std::unique_ptr<Adoptable> adoptable = nullptr;
  while (inventory.peek() != EOF) {
    readNextAdoptable(inventory, adoptable);
    mangerManagementSystem.addAdoptable(std::move(adoptable));
  }
  run_tests(mangerManagementSystem);

  return 0;
}