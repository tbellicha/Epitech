/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** tests
*/

#include "Toy.hpp"
#include "Picture.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <filesystem>
#include <unistd.h>

Test(Toy, invalid_files, .init=cr_redirect_stdout)
{
    Toy myToy;
    Toy ET(Toy::ALIEN, "green", "nferjj.txt");

    myToy.setName("TOTO !");
    if (myToy.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << myToy.getName() << std::endl << myToy.getAscii() << std::endl;
    if (ET.getType() == Toy::ALIEN)
        std::cout << "this alien is: " << ET.getName() << std::endl << ET.getAscii() << std::endl;

    cr_assert_stdout_eq_str("basic toy: TOTO !\n\nthis alien is: green\nERROR\n");
}

Test(Toy, default_toy, .init=cr_redirect_stdout)
{
    Toy myToy;

    cr_assert_eq(myToy.getName(), std::string("toy"));
    cr_assert_eq(myToy.getType(), Toy::BASIC_TOY);
    cr_assert_eq(myToy.getAscii(), std::string(""));
}

Test(Toy, custom_toy, .init=cr_redirect_stdout)
{
    Toy myToy(Toy::BASIC_TOY, "Bayblade", "./tests/idk.txt");

    cr_assert_eq(myToy.getName(), std::string("Bayblade"));
    cr_assert_eq(myToy.getType(), Toy::BASIC_TOY);
    cr_assert_eq(myToy.getAscii(), std::string("--__--\n"));
}

Test(Toy, print_toy, .init=cr_redirect_stdout)
{
    Toy myToy(Toy::BASIC_TOY, "Bayblade", "./tests/idk.txt");

    std::cout << "myToy: " << myToy.getName() << std::endl << myToy.getAscii() << std::endl;
    cr_assert_stdout_eq_str("myToy: Bayblade\n--__--\n\n");
}

Test(Toy, copy_construct, .init=cr_redirect_stdout)
{
    Toy myToy(Toy::BASIC_TOY, "Bayblade", "./tests/idk.txt");
    Toy copied(myToy);

    std::cout << "myToy: " << copied.getName() << std::endl << copied.getAscii() << std::endl;
    cr_assert_stdout_eq_str("myToy: Bayblade\n--__--\n\n");
}

Test(Toy, operator_equal, .init=cr_redirect_stdout)
{
    Toy myToy(Toy::BASIC_TOY, "Bayblade", "./tests/idk.txt");
    Toy copied;

    copied = myToy;
    std::cout << "myToy: " << copied.getName() << std::endl << copied.getAscii() << std::endl;
    cr_assert_stdout_eq_str("myToy: Bayblade\n--__--\n\n");
}

Test(Toy, operator_assign, .init=cr_redirect_stdout)
{
    Toy myToy(Toy::BASIC_TOY, "Bayblade", "./tests/idk.txt");

    cr_assert_eq(myToy.getAscii(), std::string("--__--\n"));
    myToy << "New data";
    std::cout << "myToy: " << myToy.getName() << std::endl << myToy.getAscii() << std::endl;
    cr_assert_stdout_eq_str("myToy: Bayblade\nNew data\n");
}