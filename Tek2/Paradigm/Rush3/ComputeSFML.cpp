/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH3-johan.chrillesen
** File description:
** ComputeSFML
*/

#include "ComputeSFML.hpp"
#include "IMonitorDisplay.hpp"
#include <algorithm>

void drawInfos(sf::RenderWindow *window, infos_s* infos)
{
    sf::RectangleShape rect;
    sf::RectangleShape rect_porcent;
    sf::Text text_value;
    sf::Text text_title;
    sf::Font font;
    font.loadFromFile("./OpenSans-Regular.ttf");
    rect.setPosition(infos->position);
    rect.setSize(infos->size);
    rect.setFillColor(sf::Color::White);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(2);
    text_title.setFont(font);
    text_title.setFillColor(sf::Color::Black);
    text_value.setFont(font);
    switch (infos->type) {
        case Jauge:
            text_title.setCharacterSize(14);
            text_value.setCharacterSize(32);
            text_value.setString(std::to_string(infos->value).substr(0, std::to_string(infos->value).find('.') + 4) + "%");
            text_title.setString(infos->title);
            rect_porcent.setPosition(infos->position);
            rect_porcent.setSize(sf::Vector2f((infos->size.x * (infos->value/100)), infos->size.y));
            rect_porcent.setFillColor(sf::Color::Green);
            text_title.setPosition(sf::Vector2f(infos->position.x, infos->position.y - 17));
            text_value.setPosition(sf::Vector2f(rect.getPosition().x + (rect.getSize().x/2) - (text_value.getLocalBounds().width/2), \
                rect.getPosition().y + (rect.getSize().y/2) - (text_value.getLocalBounds().height/2)));
            text_value.setFillColor(sf::Color::Black);
            break;

        case Infos:
            text_title.setCharacterSize(20);
            text_value.setCharacterSize(14);
            text_value.setFillColor(sf::Color::Blue);
            text_value.setString(infos->str_value);
            text_title.setString(infos->title + std::string(":"));
            text_title.setPosition(sf::Vector2f(infos->position.x + (infos->size.x/2) - text_title.getLocalBounds().width/2, infos->position.y));
            text_value.setPosition(sf::Vector2f(rect.getPosition().x + (rect.getSize().x/2) - (text_value.getLocalBounds().width/2), \
                rect.getPosition().y + (rect.getSize().y/2)));
            break;

        default:
            break;
    }
    window->draw(rect);
    window->draw(rect_porcent);
    window->draw(text_value);
    window->draw(text_title);
}

infos_s init_Infos(sf::Vector2f position, sf::Vector2f size, EType type, std::string title)
{
    infos_s infos;

    infos.position = position;
    infos.size = size;
    infos.type = type;
    infos.title = title;
    return (infos);
}

void drawCPUModule(sf::RenderWindow* window, AllMonitors* mc)
{
    int cpu_width = 400;
    sf::RectangleShape cpu_rect;
    sf::Vector2f base_CPU = {780, 80};
    infos_s CPU[9];
    sf::Text text_model;
    sf::Text text_nb_core;
    sf::Font font;
    font.loadFromFile("./OpenSans-Regular.ttf");
    for (int i = 0; i < 9; i++) {
        std::string cpuname("CPU" + (i == 0 ? "" : std::to_string(i - 1)));
        CPU[i] = init_Infos(sf::Vector2f(base_CPU.x, base_CPU.y + i * 80), sf::Vector2f(cpu_width, 60), Jauge, cpuname);
    }
    cpu_rect.setPosition(sf::Vector2f(base_CPU.x - 10, 10));
    cpu_rect.setSize(sf::Vector2f(cpu_width + 20, 780));
    cpu_rect.setFillColor(sf::Color(150, 150, 150));
    cpu_rect.setOutlineColor(sf::Color::Black);
    cpu_rect.setOutlineThickness(2);

    text_model.setCharacterSize(20);
    text_model.setFont(font);
    text_model.setString(mc->getCoreInfo()->_model);
    text_model.setFillColor(sf::Color::Black);
    text_model.setPosition(sf::Vector2f(base_CPU.x + (cpu_width/2) - (text_model.getLocalBounds().width/2), 14));
    text_nb_core.setCharacterSize(14);
    text_nb_core.setFont(font);
    text_nb_core.setString("Number of core: " + std::to_string(mc->getNbCore()));
    text_nb_core.setFillColor(sf::Color::Black);
    text_nb_core.setPosition(sf::Vector2f(base_CPU.x, 44));
    window->draw(cpu_rect);
    CPU[0].value = mc->getPercentageUse();
    drawInfos(window, &CPU[0]);
    for (int i = 0;  i < (int) mc->getNbCore(); i++) {
        CPU[i + 1].value = mc->getCoreInfo()[i]._percentage;
        drawInfos(window, &CPU[i + 1]);
    }
    window->draw(text_model);
    window->draw(text_nb_core);
}

void drawOthersModule(sf::RenderWindow* window, AllMonitors* mc)
{
    sf::RectangleShape ram_rect;
    ram_rect.setPosition(sf::Vector2f(290, 10));
    ram_rect.setSize(sf::Vector2f(400 + 40, 260));
    ram_rect.setFillColor(sf::Color(150, 150, 150));
    ram_rect.setOutlineColor(sf::Color::Black);
    ram_rect.setOutlineThickness(2);
    window->draw(ram_rect);

    infos_s RAM;
    RAM = init_Infos(sf::Vector2f(310, 30), sf::Vector2f(400, 60), Jauge, "RAM");
    RAM.value = mc->getRamUsed() / mc->getRamTotal() * 100;
    drawInfos(window, &RAM);

    infos_s Disk;
    Disk = init_Infos(sf::Vector2f(310, 110), sf::Vector2f(400, 60), Jauge, "Disk");
    Disk.value = 100 - mc->getDiskAvail() / mc->getDiskFree() * 100;
    drawInfos(window, &Disk);

    infos_s Network;
    std::string up = std::to_string(mc->getNetwork().getUp());
    up = up.substr(0, up.find('.') + 3);
    std::string down = std::to_string(mc->getNetwork().getDown());
    down = down.substr(0, down.find('.') + 3);
    Disk = init_Infos(sf::Vector2f(310, 190), sf::Vector2f(400, 60), Infos, "Network");
    Disk.str_value = "Up: " + up + " | Down: " + down;
    drawInfos(window, &Disk);
}


void drawSystemModule(sf::RenderWindow* window, InfoModule* im)
{
    sf::RectangleShape sys_rect;
    sys_rect.setPosition(sf::Vector2f(10, 10));
    sys_rect.setSize(sf::Vector2f(200 + 20, 360));
    sys_rect.setFillColor(sf::Color(150, 150, 150));
    sys_rect.setOutlineColor(sf::Color::Black);
    sys_rect.setOutlineThickness(2);
    window->draw(sys_rect);

    infos_s OpeSys;
    OpeSys = init_Infos(sf::Vector2f(20, 20), sf::Vector2f(200, 60), Infos, "Operating system");
    OpeSys.str_value = im->getOperatingSystem();
    drawInfos(window, &OpeSys);

    infos_s KernVers;
    KernVers = init_Infos(sf::Vector2f(20, 90), sf::Vector2f(200, 60), Infos, "Kernel version");
    KernVers.str_value = im->getKernelVersion();
    drawInfos(window, &KernVers);

    infos_s Hostname;
    Hostname = init_Infos(sf::Vector2f(20, 160), sf::Vector2f(200, 60), Infos, "Hostname");
    Hostname.str_value = im->getHostname();
    drawInfos(window, &Hostname);

    infos_s Username;
    Username = init_Infos(sf::Vector2f(20, 230), sf::Vector2f(200, 60), Infos, "Username");
    Username.str_value = im->getUsername();
    drawInfos(window, &Username);

    infos_s Date;
    Date = init_Infos(sf::Vector2f(20, 300), sf::Vector2f(200, 60), Infos, "Date");
    Date.str_value = im->getDateTime();
    drawInfos(window, &Date);
}

int actOnDisplay(IMonitorDisplay *disp, sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::I:
        disp->setDisplayInfo(!disp->getDisplayInfo());
        return 1;
    case sf::Keyboard::C:
        disp->setDisplayCPU(!disp->getDisplayCPU());
        return 1;
    case sf::Keyboard::O:
        disp->setDisplayRAM(!disp->getDisplayRAM());
        return 1;
    case sf::Keyboard::Q:
        return -1;
    default:
        return 0;
    }
}

void drawKeys(sf::RenderWindow* window)
{
    sf::Text info_text;
    sf::Font font;
    font.loadFromFile("./OpenSans-Regular.ttf");
    info_text.setCharacterSize(20);
    info_text.setFont(font);
    info_text.setString("Commands Hide/Show\nc: CPU | o: Others | i: Info | q: Quit");
    info_text.setFillColor(sf::Color::Black);
    info_text.setPosition(sf::Vector2f(20, 740));
    window->draw(info_text);
}

void computeSFML(void)
{
    sf::Event event;
    AllMonitors mc;
    InfoModule im;
    IMonitorDisplay disp;
    sf::RectangleShape bg;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "myGRellKM");

    bg.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    bg.setFillColor(sf::Color(100, 100, 100));
    while (window.isOpen()) {
        int ret = 0;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
                ret = actOnDisplay(&disp, event);
            if (ret == -1)
                window.close();
        }
        mc.setAllInfo();
        im.setAllInfos();
        window.clear();
        window.draw(bg);
        if (disp.getDisplayCPU())
            drawCPUModule(&window, &mc);
        if (disp.getDisplayRAM())
            drawOthersModule(&window, &mc);
        if (disp.getDisplayInfo())
            drawSystemModule(&window, &im);
        drawKeys(&window);
        window.display();
    }
}
