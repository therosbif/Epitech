/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** GraphWindow.cpp
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "GraphWindow.hpp"


GraphWindow::GraphWindow()
{
}

GraphWindow::~GraphWindow()
{
}

void loopSfml()
{
    // Window
    sf::ContextSettings	settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 800), "GKrellM", sf::Style::Titlebar | sf::Style::Close, settings);

    // data
    Date date;
    Hostname hname;
    KernelOS kernel;
    Ram ram;
    Cpu cpu;


    sf::Font font;

    if (!font.loadFromFile("rsrc/Heebo_2.ttf"))
        exit(84);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Text separatorInfo("<<----->> INFO <<----->>", font, 20);

        sf::Text dateInfo("\n" + date.getDay() + "/" + date.getMonth() + "/" + date.getYear() + "    " + date.getHour() + "." + date.getMin() + "." + date.getSec(), font, 20);
        sf::Text hostInfo("\n\n" + hname.getUser() + " - " + hname.getHost(), font, 20);
        sf::Text kernelInfo("\n\n\n" + kernel.getOSName() + " - " + kernel.getKernelVersion(), font, 20);
        sf::Text separator("\n\n\n\n<<----->> CPU <<----->>", font, 20);
        sf::Text cpuInfo("\n\n\n\n\n" + std::to_string(cpu.getCores()) + " cores", font, 20);
        sf::Text tmpCpu("\n\n\n\n\n\n" + std::to_string(cpu.getTemp()) + "  *C", font, 20);
        sf::Text tmpCputotal("\n\n\n\n\n\n\n" + std::to_string(cpu.getTotal()), font, 20);
        sf::Text separatorRam("\n\n\n\n\n\n\n\n<<----->> RAM <<----->>", font, 20);
        sf::Text TotalRam("\n\n\n\n\n\n\n\n\nTotal: " +  std::to_string(ram.getTotalMem()) + " Kb", font, 20);
        sf::Text availRam("\n\n\n\n\n\n\n\n\n\nAvailable: " +  std::to_string(ram.getAvailMem()) + " Kb", font, 20);
        sf::Text freeRam("\n\n\n\n\n\n\n\n\n\n\nFree: " +  std::to_string(ram.getFreeMem()) + " Kb", font, 20);
        sf::Text usedRam("\n\n\n\n\n\n\n\n\n\n\n\nUsed: " +  std::to_string(ram.getUsedMem()) + " Kb", font, 20);

        date.refreshInfo();
        cpu.refreshInfo();
        window.display();
        window.clear();
        window.draw(separatorInfo);
        window.draw(dateInfo);
        window.draw(hostInfo);
        window.draw(kernelInfo);
        window.draw(separator);
        window.draw(cpuInfo);
        window.draw(tmpCpu);
        window.draw(tmpCputotal);
        window.draw(separatorRam);
        window.draw(TotalRam);
        window.draw(availRam);
        window.draw(freeRam);
        window.draw(usedRam);

        sleep(1);
    }
}