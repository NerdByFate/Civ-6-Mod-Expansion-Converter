#include "MainState.h"

MainState::MainState() {
	filesHandled = false;
	convertPressed = false;
	SetPositionSet(false);

	buttonGridTexture = new sf::Texture;

	if (!buttonGridTexture->loadFromFile("button_grid.png", sf::IntRect(0, 0, 1276, 716))) {
		std::cout << "Could not load texture buttonGridTexture. If you are reading this, please exit the application.\n";
	}

	if (!rf0.loadFromFile("rf_button_unpressed.png", sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture rf0. If you are reading this, please exit the application.\n";
	}
	if (!rf1.loadFromFile("rf_button_pressed.png", sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture rf1. If you are reading this, please exit the application.\n";
	}
	if (!gs0.loadFromFile("gs_button_unpressed.png", sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture gs0. If you are reading this, please exit the application.\n";
	}
	if (!gs1.loadFromFile("gs_button_pressed.png", sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture gs1. If you are reading this, please exit the application.\n";
	}
	if (!convert0.loadFromFile("convert_button_unpressed.png", sf::IntRect(0, 0, 128, 64))) {
		std::cout << "Could not load texture convert0. If you are reading this, please exit the application.\n";
	}
	if (!convert1.loadFromFile("convert_button_pressed.png", sf::IntRect(0, 0, 128, 64))) {
		std::cout << "Could not load texture convert1. If you are reading this, please exit the application.\n";
	}
	if (!gen0.loadFromFile("gen_button_unpressed.png", sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture gen0. If you are reading this, please exit the application.\n";
	}
	if (!gen1.loadFromFile("gen_button_pressed.png", sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture gen1. If you are reading this, please exit the application.\n";
	}

	if (!trebuc.loadFromFile("trebuc.ttf")) {
		std::cout << "Could not load font trebuc. If you are reading this, please exit the application.\n";
	}

	gen0.setSmooth(true);
	gen1.setSmooth(true);

	background.setSize(sf::Vector2f(1276, 716));
	background.setPosition(2.0f, 2.0f);
	background.setFillColor(sf::Color(0, 34, 255, 255));
	background.setOutlineColor(sf::Color(0, 255, 255, 255));
	background.setOutlineThickness(2.0f);

	buttonGrid.setPrimitiveType(sf::Quads);
	buttonGrid.resize(4);
	buttonGrid[0].position = sf::Vector2f(background.getPosition().x, background.getPosition().y);
	buttonGrid[1].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y);
	buttonGrid[2].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y);
	buttonGrid[3].position = sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y);

	buttonGrid[0].texCoords = sf::Vector2f(background.getPosition().x, background.getPosition().y);
	buttonGrid[1].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y);
	buttonGrid[2].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y);
	buttonGrid[3].texCoords = sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y);

	convert.SetButtonUnpressedTexture(&gen0);
	convert.SetButtonPressedTexture(&gen1);
	convert.setScale(2.0f, 1.0f);
	sf::Text temp = convert.GetButtonText();
	temp.setString("Convert");
	convert.SetButtonText(temp);

	riseAndFall.SetButtonUnpressedTexture(&rf0);
	riseAndFall.SetButtonPressedTexture(&rf1);
	riseAndFall.SetButtonText(sf::Text());

	gatheringStorm.SetButtonUnpressedTexture(&gs0);
	gatheringStorm.SetButtonPressedTexture(&gs1);
	gatheringStorm.SetButtonText(sf::Text());

	cList.setPosition(100, 50);

	scrolling = false;
	delta = 0;
}

int MainState::Render(sf::RenderWindow& window) {
	HandleEvents(window);
	cList.HandleEvents(window);

	if (!filesHandled) {
		std::vector<std::experimental::filesystem::path> tempV;

		for (const auto & entry : std::experimental::filesystem::directory_iterator((std::string)path)) {
			std::cout << entry.path() << std::endl;
			for (const auto & entry2 : std::experimental::filesystem::directory_iterator((std::string)entry.path().u8string())) {
				for (const auto & entry3 : std::experimental::filesystem::directory_iterator((std::string)entry2.path().u8string())) {
					if (entry3.path().filename().u8string().find("Config") != std::string::npos || entry3.path().filename().u8string().find("config") != std::string::npos) {
						if (entry3.path().extension().u8string() == ".xml") {
							tempV.push_back(entry3.path());
						}
					}
				}
				if (entry2.path().filename().u8string().find("Config") != std::string::npos || entry2.path().filename().u8string().find("config") != std::string::npos) {
					if (entry2.path().extension().u8string() == ".xml") {
						tempV.push_back(entry2.path());
					}
				}
			}
		}

		cList.InsertItems(tempV);

		filesHandled = true;
	}

	if (convertPressed) {
		std::vector<XMLLine> temp;
		XMLLine tempL;
		std::vector<std::experimental::filesystem::path> selectedPaths;

		for (int i = 0; i < cList.GetItems().size(); i++) {
			if (cList.GetCheckboxes()[i].GetManualPressed() == true) {
				selectedPaths.push_back(cList.GetItems()[i]);
			}
		}

		for (int i = 0; i < selectedPaths.size(); i++) {
			xStream.open(selectedPaths[i].u8string());
			xStream.inputLines();
			temp = xStream.GetLines();
			int x = xStream.GetLines().size();

			std::cout << xStream.GetPath() << std::endl;
			
			for (int c = 0; c < x; c++) {
				for (int z = 0; z < xStream.GetLines()[c].GetParts().size(); z++) {
					if (xStream.GetLines()[c].GetPart(z).find("Domain=\"StandardPlayers\"") != std::string::npos && GetGatheringStormButton().GetManualPressed() == false && GetRiseAndFallButton().GetManualPressed() == true) {
						xStream.InsertLine(c, xStream.GetLines()[c]);
						tempL = xStream.GetLines()[c];
						tempL.SetPart(z, "Domain=\"Players:Expansion1_Players\"");
						temp = xStream.GetLines();
						temp[c] = tempL;
						xStream.SetLines(temp);
						++x;
						c++;
					}
					else if (xStream.GetLines()[c].GetPart(z).find("Domain=\"StandardPlayers\"") != std::string::npos && GetGatheringStormButton().GetManualPressed() == true && GetRiseAndFallButton().GetManualPressed() == false) {
						xStream.InsertLine(c, xStream.GetLines()[c]);
						tempL = xStream.GetLines()[c];
						tempL.SetPart(z, "Domain=\"Players:Expansion2_Players\"");
						temp = xStream.GetLines();
						temp[c] = tempL;
						xStream.SetLines(temp);
						++x;
						c++;
					}
					else if (xStream.GetLines()[c].GetPart(z).find("Domain=\"StandardPlayers\"") != std::string::npos && GetGatheringStormButton().GetManualPressed() == true && GetRiseAndFallButton().GetManualPressed() == true) {
						xStream.InsertLine(c, xStream.GetLines()[c]);
						xStream.InsertLine(c, xStream.GetLines()[c]);
						tempL = xStream.GetLines()[c];
						tempL.SetPart(z, "Domain=\"Players:Expansion1_Players\"");
						temp = xStream.GetLines();
						temp[c] = tempL;
						tempL.SetPart(z, "Domain=\"Players:Expansion2_Players\"");
						temp[c + 1] = tempL;
						xStream.SetLines(temp);
						x += 2;
						c += 2;
					}
					else if (xStream.GetLines()[c].GetPart(z - 1).find("Domain") == std::string::npos && xStream.GetLines()[c].GetPart(z).find("CivilizationType") != std::string::npos && GetGatheringStormButton().GetManualPressed() == false && GetRiseAndFallButton().GetManualPressed() == true) {
						xStream.InsertLine(c, xStream.GetLines()[c]);
						tempL = xStream.GetLines()[c];
						tempL.Insert("Domain=\"Players:Expansion1_Players\"", z);
						temp = xStream.GetLines();
						temp[c] = tempL;
						xStream.SetLines(temp);
						++x;
						c++;
					}
					else if (xStream.GetLines()[c].GetPart(z - 1).find("Domain") == std::string::npos && xStream.GetLines()[c].GetPart(z).find("CivilizationType") != std::string::npos && GetGatheringStormButton().GetManualPressed() == true && GetRiseAndFallButton().GetManualPressed() == false) {
						xStream.InsertLine(c, xStream.GetLines()[c]);
						tempL = xStream.GetLines()[c];
						tempL.Insert("Domain=\"Players:Expansion2_Players\"", z);
						temp = xStream.GetLines();
						temp[c] = tempL;
						xStream.SetLines(temp);
						++x;
						c++;
					}
					else if (xStream.GetLines()[c].GetPart(z - 1).find("Domain") == std::string::npos && xStream.GetLines()[c].GetPart(z).find("CivilizationType") != std::string::npos && GetGatheringStormButton().GetManualPressed() == true && GetRiseAndFallButton().GetManualPressed() == true) {
						xStream.InsertLine(c, xStream.GetLines()[c]);
						xStream.InsertLine(c, xStream.GetLines()[c]);
						tempL = xStream.GetLines()[c];
						tempL.Insert("Domain=\"Players:Expansion1_Players\"", z);
						temp = xStream.GetLines();
						temp[c] = tempL;
						tempL.Delete(z);
						tempL.Insert("Domain=\"Players:Expansion2_Players\"", z);
						temp[c + 1] = tempL;
						xStream.SetLines(temp);
						x += 2;
						c += 2;
					}
				}
			}
			xStream.close();
			xStream.outputLines();

			xStream = XMLStream();
		}

		convertPressed = false;
		window.setView(window.getDefaultView());
		return 3;
	}

	if (!GetPositionSet()) {
		convert.setPosition(window.getSize().x - convert.GetWidth(), window.getSize().y - convert.GetHeight());
		riseAndFall.setPosition(743, 82);
		gatheringStorm.setPosition(934, 82);

		convert.UpdatePositions();
		SetPositionSet(true);
	}

	window.clear();
	window.setView(window.getDefaultView());
	window.draw(GetBackground());
	window.draw(GetButtonGrid(), sf::RenderStates(GetButtonGridTexture()));
	window.draw(GetConvertButton());
	window.draw(GetRiseAndFallButton());
	window.draw(GetGatheringStormButton());

	window.draw(GetChecklist());
	window.display();

	return 2;
}

void MainState::HandleEvents(sf::RenderWindow& window) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseWheelScrolled:
			float temp = GetChecklist().GetScrollBox().getPosition().y;
			if (event.mouseWheelScroll.wheel == sf::Mouse::Wheel::VerticalWheel) {
				cList.Scroll(temp - (event.mouseWheelScroll.delta * 10));
			}
			break;
		}
	}

	if (riseAndFall.isButtonPressed(window) && riseAndFall.GetManualPressed() == false && checkTimer.getElapsedTime().asSeconds() >= 0.15f) {
		riseAndFall.SetManualPressed(true);
		checkTimer.restart();
	}
	else if (riseAndFall.isButtonPressed(window) && riseAndFall.GetManualPressed() == true && checkTimer.getElapsedTime().asSeconds() >= 0.15f) {
		riseAndFall.SetManualPressed(false);
		checkTimer.restart();
	}

	if (gatheringStorm.isButtonPressed(window) && gatheringStorm.GetManualPressed() == false && checkTimer.getElapsedTime().asSeconds() >= 0.15f) {
		gatheringStorm.SetManualPressed(true);
		checkTimer.restart();
	}
	else if (gatheringStorm.isButtonPressed(window) && gatheringStorm.GetManualPressed() == true && checkTimer.getElapsedTime().asSeconds() >= 0.15f) {
		gatheringStorm.SetManualPressed(false);
		checkTimer.restart();
	}

	if (convert.isButtonPressed(window)) {
		convert.SetManualPressed(true);
		convertPressed = true;
	}
	else {
		convert.SetManualPressed(false);
	}

	if (cList.upArrow.isButtonPressed(window)) {
		cList.upArrow.SetManualPressed(true);
		cList.Scroll(cList.GetScrollBox().getPosition().y - 10);
	}
	else {
		cList.upArrow.SetManualPressed(false);
	}

	if (cList.downArrow.isButtonPressed(window)) {
		cList.downArrow.SetManualPressed(true);
		cList.Scroll(cList.GetScrollBox().getPosition().y + 10);
	}
	else {
		cList.downArrow.SetManualPressed(false);
	}

	if (!scrolling && sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= cList.GetScrollBox().getPosition().x && sf::Mouse::getPosition(window).x <= cList.GetScrollBox().getPosition().x + cList.GetScrollBox().getSize().x && sf::Mouse::getPosition(window).y >= cList.GetScrollBox().getPosition().y && sf::Mouse::getPosition(window).y <= cList.GetScrollBox().getPosition().y + cList.GetScrollBox().getSize().y) {
		scrolling = true;
		if (sf::Mouse::getPosition(window).y != GetChecklist().GetScrollBox().getPosition().y) {
			delta = sf::Mouse::getPosition(window).y - GetChecklist().GetScrollBox().getPosition().y;
		}
	}
	if (scrolling && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		scrolling = false;
		cList.Scroll(sf::Mouse::getPosition(window).y - delta);
		delta = 0;
	}
}

sf::String MainState::GetPath() const {
	return path;
}

void MainState::SetPath(sf::String pathToSteam) {
	path = pathToSteam;
}

sf::RectangleShape MainState::GetBackground() const {
	return background;
}

void MainState::SetBackground(sf::RectangleShape bg) {
	background = bg;
}

sf::Texture MainState::GetRiseAndFallUnpressed() const {
	return rf0;
}

void MainState::SetRiseAndFallUnpressed(sf::Texture rfu) {
	rf0 = rfu;
}

sf::Texture MainState::GetRiseAndFallPressed() const {
	return rf1;
}

void MainState::SetRiseAndFallPressed(sf::Texture rfp) {
	rf1 = rfp;
}

sf::Texture MainState::GetGatheringStormUnpressed() const {
	return gen0;
}

void MainState::SetGatheringStormUnpressed(sf::Texture gsu) {
	gs0 = gsu;
}

sf::Texture MainState::GetGatheringStormPressed() const {
	return gs1;
}

void MainState::SetGatheringStormPressed(sf::Texture gsp) {
	gs1 = gsp;
}

sf::Texture MainState::GetConvertUnpressed() const {
	return convert0;
}

void MainState::SetConvertUnpressed(sf::Texture convertu) {
	convert0 = convertu;
}

sf::Texture MainState::GetConvertPressed() const {
	return convert1;
}

void MainState::SetConvertPressed(sf::Texture convertp) {
	convert1 = convertp;
}

sf::Texture MainState::GetGenericUnpressed() const {
	return gen0;
}

void MainState::SetGenericUnpressed(sf::Texture genu) {
	gen0 = genu;
}

sf::Texture MainState::GetGenericPressed() const {
	return gen1;
}

void MainState::SetGenericPressed(sf::Texture genp) {
	gen1 = genp;
}

Button MainState::GetRiseAndFallButton() const {
	return riseAndFall;
}

void MainState::SetRiseAndFallButton(Button rfs) {
	riseAndFall = rfs;
}

Button MainState::GetGatheringStormButton() const {
	return gatheringStorm;
}

void MainState::SetGatheringStormButton(Button gss) {
	gatheringStorm = gss;
}

Button MainState::GetConvertButton() const {
	return convert;
}

void MainState::SetConvertButton(Button converts) {
	convert = converts;
}

sf::Font MainState::GetFont() const {
	return trebuc;
}

void MainState::SetFont(sf::Font font) {
	trebuc = font;
}

sf::Text MainState::GetExpansionHeaderText() const {
	return expansionHeader;
}

void MainState::SetExpansionHeaderText(sf::Text expHeader) {
	expansionHeader = expHeader;
}

sf::Text MainState::GetModNamesText() const {
	return modNames;
}

void MainState::SetModNamesText(sf::Text mods) {
	modNames = mods;
}

sf::Text MainState::GetDoneText() const {
	return done;
}

void MainState::SetDoneText(sf::Text d) {
	done = d;
}

Checklist MainState::GetChecklist() const {
	return cList;
}

void MainState::SetChecklist(Checklist c) {
	cList = c;
}

sf::VertexArray MainState::GetButtonGrid() const {
	return buttonGrid;
}

void MainState::SetButtonGrid(sf::VertexArray bGrid) {
	buttonGrid = bGrid;
}

sf::Texture* MainState::GetButtonGridTexture() const {
	return buttonGridTexture;
}

void MainState::SetButtonGridTexture(sf::Texture* bGridTexture) {
	buttonGridTexture = bGridTexture;
}
