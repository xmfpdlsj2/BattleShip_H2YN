#include "Player.h"
#include "AircraftCarrier.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include <time.h>
#include "Position.h"

CPlayer::CPlayer()
{
	pShipVector.push_back(new CAircraftCarrier());
	pShipVector.push_back(new CBattleShip());
	pShipVector.push_back(new CCruiser());
	pShipVector.push_back(new CDestroyer());
	pShipVector.push_back(new CDestroyer());
}


CPlayer::~CPlayer()
{
	for (auto pVar : pShipVector)
	{
		delete pVar;
	}
}

void CPlayer::PlaceShip()
{
	srand((unsigned)time(NULL));
	bool northPossible = true, southPossible = true, westPossible = true, eastPossible = true;

	for (auto pShip : pShipVector)
	{
		for (auto i = 0; i < pShip->GetDurabilitySize(); i++)
		{
			while (1) //Position �´°� ���ö����� �ݺ�
			{
				int x = rand() % 8 + 1; // ���� �Է� ���� ������ x�� 1~8���״ϱ�
				int y = rand() % 8;
				Position position;
				position.x = (char)(x + '0');
				position.y = (char)(y + 'A');
				
				if (_CheckPossiblePosition(pShip, position)) {
					pShip->AddPosition(position);
					switch (pShip->GetShipType())
					{
					case AIRCRAFT_CARRIER:
						m_PlayerBoard.SetMapPosition(x-1, y, A);
						break;
					case BATTLESHIP:
						m_PlayerBoard.SetMapPosition(x-1, y, B);
						break;
					case CRUISER:
						m_PlayerBoard.SetMapPosition(x-1, y, C);
						break;
					case DESTROYER:
						m_PlayerBoard.SetMapPosition(x-1, y, D);
						break;
					case SUBMARINE:
						m_PlayerBoard.SetMapPosition(x-1, y, S);
						break;
					default:
						break;
					}
					printf("Input Position Of %s (%c,%c)\n", pShip->GetName().c_str(), position.x, position.y);
					break;
				}
			} 
		}

	}
}

void CPlayer::PrintShipVector()
{
	for (int i = 0; i < (int)pShipVector.size(); i++)
	{
		pShipVector[i]->PrintTest();
	}
}

bool CPlayer::_CheckPossiblePosition(CShip * pShip, Position position)
{
	// ���� �������� ���� ���������� static���� ����س����� �� ������?!!

	int x = (int)(position.x - '1');
	int y = (int)(position.y - 'A');

	if (m_PlayerBoard.GetMapPosition(x, y) != NONE) // ������ ��ǥ �������� ������
		return false;

	if (pShip->GetShipPosition().empty()) // �迡 �ϳ��� ������ ���� �ʾ��� ���
	{
		if (_CheckPossibleLine(position, pShip->GetDurabilitySize(), ROW))
			return true;
		if (_CheckPossibleLine(position, pShip->GetDurabilitySize(), COLUMN))
			return true;

		return false; // ���� ���� �� �� �ȵ� ��
	}
	else
	{
		if (pShip->GetShipPosition().size() == 1) // �迡 ������ �ϳ� ����Ǿ� ���� ���
		{
			Position alreadyExistPosition = pShip->GetShipPosition()[0];

			if (abs((int)(alreadyExistPosition.x - position.x)) == 1 &&
				(int)(alreadyExistPosition.y - position.y) == 0) // ���� �ִ� x�� �˻��� x�� �ϳ� ���� �� ��(������ ��)
			{
				if (_CheckPossibleLine(alreadyExistPosition, pShip->GetDurabilitySize(), ROW)) // �˻��� �� �̹� ����Ǿ� �ִ� ���������� �˻��غ�����!
					return true;
			}
			else if (abs((int)(alreadyExistPosition.y - position.y)) == 1 &&
				(int)(alreadyExistPosition.x - position.x) == 0) // ���� �ִ� y�� �˻��� y�� �ϳ� ���� �� ��(������ ��)
			{
				if (_CheckPossibleLine(alreadyExistPosition, pShip->GetDurabilitySize(), COLUMN))
					return true;
			}
			else
				return false;

			return false;
		}
		else // �迡 ������ �ΰ� �̻� ����Ǿ� ���� ���
		{
			char min, max;

			if (pShip->GetShipPosition()[0].y == pShip->GetShipPosition()[1].y) // ������ ��
			{
				if (pShip->GetShipPosition()[0].y != position.y) // ���� ���η� ��ġ �Ǿ��־����� �޾ƿ��°͵� y�� ���ƾ���
					return false;

				min = pShip->GetShipPosition()[0].x, max = pShip->GetShipPosition()[0].x;

				for (int i = 1; i < (int)pShip->GetShipPosition().size(); i++)
				{
					if (pShip->GetShipPosition()[i].x < min)
						min = pShip->GetShipPosition()[i].x;
					if (pShip->GetShipPosition()[i].x > max)
						max = pShip->GetShipPosition()[i].x;
				}
				//printf("ROW, min = %c, max = %c\n", min, max);
				if ((int)(min - position.x) == 1 || (int)(position.x - max) == 1)
					return true;
				else
					return false;
			}

			if (pShip->GetShipPosition()[0].x == pShip->GetShipPosition()[1].x) //������ ��
			{
				if (pShip->GetShipPosition()[0].x != position.x) // ���� ���η� ��ġ �Ǿ��־����� �޾ƿ��°͵� x�� ���ƾ���
					return false;

				min = pShip->GetShipPosition()[0].y, max = pShip->GetShipPosition()[0].y;

				for (int i = 1; i < (int)pShip->GetShipPosition().size(); i++)
				{
					if (pShip->GetShipPosition()[i].y < min)
						min = pShip->GetShipPosition()[i].y;
					if (pShip->GetShipPosition()[i].y > max)
						max = pShip->GetShipPosition()[i].y;
				}
				//printf("COLUMN, min = %c, max = %c\n", min, max);
				if ((int)(min - position.y) == 1 || (int)(position.y - max) == 1)
					return true;
				else
					return false;
			}

			printf("Line Type is error at line num %d in %s in %s\n", __LINE__, __FUNCTION__, __FILE__);
			return false;
		}
	}

	return false;
}

bool CPlayer::_CheckPossibleLine(Position checkPosition, int shipSize, ELineType lineType)
{
	int x = (int)(checkPosition.x - '1');
	int y = (int)(checkPosition.y - 'A');

	int count = 1; // �˻��� ���� �������� �ֱ� �����ϴٴ� ���� ������
	int mapSize = m_PlayerBoard.GetMapSize();

	if (lineType == ROW)
	{
		bool westPossible = true, eastPossible = true;

		for (auto i = 1; i < shipSize; i++) // ���η� ������ ĭ Ȯ���� �������� �˻�
		{
			if (eastPossible && (x + i) < mapSize && m_PlayerBoard.GetMapPosition(x + i, y) == NONE)
				++count;
			else
				eastPossible = false;

			if (westPossible && (x - i) >= 0 && m_PlayerBoard.GetMapPosition(x - i, y) == NONE)
				++count;
			else
				westPossible = false;

			if (count >= shipSize)
				return true;
		}
		return false;
	}
	else if (lineType == COLUMN)
	{
		bool northPossible = true, southPossible = true;

		for (auto i = 1; i < shipSize; i++) // ���η� ������ ĭ Ȯ���� �������� �˻�
		{
			if (southPossible && (y + i) < mapSize && m_PlayerBoard.GetMapPosition(x, y + i) == NONE)
				++count;
			else
				southPossible = false;

			if (northPossible && (y - i) >= 0 && m_PlayerBoard.GetMapPosition(x, y - i) == NONE)
				++count;
			else
				northPossible = false;

			if (count >= shipSize)
				return true;
		}
		return false;
	}
	else
		return false;

	return false;
}
