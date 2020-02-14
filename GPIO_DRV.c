#include"STD_TYPES.h"
#include"Utils.h"
#include"MEM_MAP.h"
#include "GPIO_DRV.h"
void GPIO_PORT_INIT(GPIOPortID_t port, GPIODirection_t dir,
                    GPIOCurrent_t current)
{
    switch (port)
    {
    case PA:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 0);
        PORTADEN = 0xFF;
        switch (dir)
        {
        case OUT:
            PORTADIR = 0xFF;
            if (current == I_2mA)
            {
                PORTADR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                PORTADR4R = 0xFF;
            }
            else
            {
                PORTADR8R = 0xFF;
            }
            break;

        case INOPENDRAIN:
            PORTADIR = 0x00;
            PORTBODR = 0xFF;
            break;
        case INPULLUP:
            PORTADIR = 0x00;
            PORTAPUR = 0xFF;
            break;

        case INPULLDOWN:
            PORTADIR = 0x00;
            PORTAPDR = 0xFF;
            break;

        }
        break;

    case PB:
        SET_BIT(RCGCGPIO, 1);
        PORTBDEN = 0xFF;

        switch (dir)
        {
        case OUT:
            PORTBDIR = 0xFF;
            if (current == I_2mA)
            {
                PORTBDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                PORTBDR4R = 0xFF;
            }
            else
            {
                PORTBDR8R = 0xFF;
            }
            break;

        case INOPENDRAIN:
            PORTBDIR = 0x00;
            PORTBODR = 0xFF;
            break;
        case INPULLUP:
            PORTBDIR = 0x00;
            PORTBPUR = 0xFF;
            break;

        case INPULLDOWN:
            PORTBDIR = 0x00;
            PORTBPDR = 0xFF;
            break;

        }
        break;

    case PC:
        SET_BIT(RCGCGPIO, 2);

        //unlock pin 0,1,3
        PORTCLOCK = 0x4C4F434B;
        PORTCCR = 0x0F; //(1) | (1 << 1) | (1 << 2) | (1 << 3);

        PORTCDEN = 0xFF;
        switch (dir)
        {
        case OUT:
            PORTCDIR = 0xFF;
            if (current == I_2mA)
            {
                PORTCDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                PORTCDR4R = 0xFF;
            }
            else
            {
                PORTCDR8R = 0xFF;
            }
            break;

        case INOPENDRAIN:
            PORTCDIR = 0x00;
            PORTCODR = 0xFF;
            break;
        case INPULLUP:
            PORTCDIR = 0x00;
            PORTCPUR = 0xFF;
            break;

        case INPULLDOWN:
            PORTCDIR = 0x00;
            PORTCPDR = 0xFF;
            break;

        }
        break;

    case PD:
        SET_BIT(RCGCGPIO, 3);
        //unlock pin 7
        PORTDLOCK = 0x4C4F434B;
        PORTDCR = 0x80;

        PORTDDEN = 0xFF;

        switch (dir)
        {
        case OUT:
            PORTDDIR = 0xFF;
            if (current == I_2mA)
            {
                PORTDDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                PORTDDR4R = 0xFF;
            }
            else
            {
                PORTDDR8R = 0xFF;
            }
            break;

        case INOPENDRAIN:
            PORTDDIR = 0x00;
            PORTDODR = 0xFF;
            break;
        case INPULLUP:
            PORTDDIR = 0x00;
            PORTDPUR = 0xFF;
            break;

        case INPULLDOWN:
            PORTDDIR = 0x00;
            PORTDPDR = 0xFF;
            break;

        }
        break;
    case PE:
        SET_BIT(RCGCGPIO, 4);
        PORTEDEN = 0xFF;

        switch (dir)
        {
        case OUT:
            PORTEDIR = 0xFF;
            if (current == I_2mA)
            {
                PORTEDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                PORTEDR4R = 0xFF;
            }
            else
            {
                PORTEDR8R = 0xFF;
            }
            break;

        case INOPENDRAIN:
            PORTEDIR = 0x00;
            PORTEODR = 0xFF;
            break;
        case INPULLUP:
            PORTEDIR = 0x00;
            PORTEPUR = 0xFF;
            break;

        case INPULLDOWN:
            PORTEDIR = 0x00;
            PORTEPDR = 0xFF;
            break;

        }
        break;

    case PF:

        SET_BIT(RCGCGPIO, 5);

        //unlock pin 0
        PORTFLOCK = 0x4C4F434B;
        PORTFCR = 0x01;

        PORTFDEN = 0xFF;
        switch (dir)
        {
        case OUT:
            PORTFDIR = 0xFF;
            if (current == I_2mA)
            {
                PORTFDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                PORTFDR4R = 0xFF;
            }
            else
            {
                PORTFDR8R = 0xFF;
            }
            break;

        case INOPENDRAIN:
            PORTFDIR = 0x00;
            PORTFODR = 0xFF;
            break;
        case INPULLUP:
            PORTFDIR = 0x00;
            PORTFPUR = 0xFF;
            break;

        case INPULLDOWN:
            PORTFDIR = 0x00;
            PORTFPDR = 0xFF;
            break;

        }
        break;

    }

}

void GPIO_PIN_INIT(GPIOPortID_t port, GPIOPinID_t pin, GPIODirection_t dir,
                   GPIOCurrent_t current)
{
    switch (port)
    {
    case PA:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 0);
        SET_BIT(PORTADEN, pin);
        switch (dir)
        {
        case OUT:
            SET_BIT(PORTADIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(PORTADR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(PORTADR4R, pin);

            }
            else
            {
                SET_BIT(PORTADR8R, pin);
            }
            break;

        case INOPENDRAIN:
            CLR_BIT(PORTADIR, pin);
            SET_BIT(PORTAODR, pin);
            break;
        case INPULLUP:
            CLR_BIT(PORTADIR, pin);
            SET_BIT(PORTAPUR, pin);
        case INPULLDOWN:
            CLR_BIT(PORTADIR, pin);
            SET_BIT(PORTAPDR, pin);

            break;
        }
        break;
    case PB:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 1);
        SET_BIT(PORTBDEN, pin);
        switch (dir)
        {
        case OUT:
            SET_BIT(PORTBDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(PORTBDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(PORTBDR4R, pin);

            }
            else
            {
                SET_BIT(PORTBDR8R, pin);
            }
            break;

        case INOPENDRAIN:
            CLR_BIT(PORTBDIR, pin);
            SET_BIT(PORTBODR, pin);
            break;
        case INPULLUP:
            CLR_BIT(PORTBDIR, pin);
            SET_BIT(PORTBPUR, pin);
        case INPULLDOWN:
            CLR_BIT(PORTBDIR, pin);
            SET_BIT(PORTBPDR, pin);

            break;
        }
        break;

    case PC:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 2);

        if (pin == 0 | pin == 1 | pin == 2 | pin == 3)
        {
            PORTCLOCK = 0x4C4F434B;
            PORTCCR = 0X0F; //(1) | (1 << 1) | (1 << 2) | (1 << 3);

        }
        SET_BIT(PORTCDEN, pin);

        switch (dir)
        {
        case OUT:
            SET_BIT(PORTCDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(PORTCDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(PORTCDR4R, pin);

            }
            else
            {
                SET_BIT(PORTCDR8R, pin);
            }
            break;

        case INOPENDRAIN:
            CLR_BIT(PORTCDIR, pin);
            SET_BIT(PORTCODR, pin);
            break;
        case INPULLUP:
            CLR_BIT(PORTCDIR, pin);
            SET_BIT(PORTCPUR, pin);
        case INPULLDOWN:
            CLR_BIT(PORTCDIR, pin);
            SET_BIT(PORTCPDR, pin);

            break;
        }
        break;

    case PD:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 3);

        if (pin == 7)
        {

            PORTDLOCK = 0x4C4F434B;
            PORTDCR = 0x80;
        }
        SET_BIT(PORTDDEN, pin);
        switch (dir)
        {
        case OUT:
            SET_BIT(PORTDDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(PORTDDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(PORTDDR4R, pin);

            }
            else
            {
                SET_BIT(PORTDDR8R, pin);
            }
            break;

        case INOPENDRAIN:
            CLR_BIT(PORTDDIR, pin);
            SET_BIT(PORTDODR, pin);
            break;
        case INPULLUP:
            CLR_BIT(PORTDDIR, pin);
            SET_BIT(PORTDPUR, pin);
        case INPULLDOWN:
            CLR_BIT(PORTDDIR, pin);
            SET_BIT(PORTDPDR, pin);

            break;
        }
        break;

    case PE:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 4);
        SET_BIT(PORTEDEN, pin);
        switch (dir)
        {
        case OUT:
            SET_BIT(PORTEDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(PORTEDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(PORTEDR4R, pin);

            }
            else
            {
                SET_BIT(PORTEDR8R, pin);
            }
            break;

        case INOPENDRAIN:
            CLR_BIT(PORTEDIR, pin);
            SET_BIT(PORTEODR, pin);
            break;
        case INPULLUP:
            CLR_BIT(PORTEDIR, pin);
            SET_BIT(PORTEPUR, pin);
        case INPULLDOWN:
            CLR_BIT(PORTEDIR, pin);
            SET_BIT(PORTEPDR, pin);

            break;
        }
        break;

    case PF:
        //enable clock for the port
        SET_BIT(RCGCGPIO, 5);

        if (pin == 0)
        {

            PORTFLOCK = 0x4C4F434B;
            PORTFCR = 0x01;
        }
        SET_BIT(PORTFDEN, pin);
        switch (dir)
        {
        case OUT:
            SET_BIT(PORTFDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(PORTFDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(PORTFDR4R, pin);

            }
            else
            {
                SET_BIT(PORTFDR8R, pin);
            }
            break;

        case INOPENDRAIN:
            CLR_BIT(PORTFDIR, pin);
            SET_BIT(PORTFODR, pin);
            break;
        case INPULLUP:
            CLR_BIT(PORTFDIR, pin);
            SET_BIT(PORTFPUR, pin);
        case INPULLDOWN:
            CLR_BIT(PORTFDIR, pin);
            SET_BIT(PORTFPDR, pin);

            break;
        }
        break;

    }

}

void GPIO_WRITE_PORT(GPIOPortID_t port, uint8 value)
{
    switch (port)
    {
    case PA:
        PORTADAT = value;
        break;
    case PB:
        PORTBDAT = value;
        break;
    case PC:
        PORTCDAT = value;
        break;
    case PD:
        PORTDDAT = value;
        break;

    case PE:
        PORTEDAT = value;
        break;

    case PF:
        PORTFDAT = value;
        break;
    }
}

void GPIO_WRITE_PIN(GPIOPortID_t port, GPIOPinID_t pin, uint8 value)
{

    switch (port)
    {
    case PA:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40004000 + (1 << (pin + 2))))) = 0XFF;
        }
        else
        {
            (*((volatile uint32*) (0x40004000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    case PB:
        if (value == 1)
        {

            (*((volatile uint32*) (0x40005000 + (1 << (pin + 2))))) = 0xFF;
        }
        else
        {
            (*((volatile uint32*) (0x40005000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    case PC:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40006000 + (1 << (pin + 2))))) = 0xFF;
        }
        else
        {
            (*((volatile uint32*) (0x40006000 + (1 << (pin + 2))))) = 0x00;
        }
        break;

    case PD:
        if (value == 1)
        {

            (*((volatile uint32*) (0x40007000 + (1 << (pin + 2))))) = 0XFF;

        }
        else
        {
            (*((volatile uint32*) (0x40007000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    case PE:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40024000 + (1 << (pin + 2))))) = 0XFF;
        }
        else
        {
            (*((volatile uint32*) (0x40024000 + (1 << (pin + 2))))) = 0X00;
        }
        break;
    case PF:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40025000 + (1 << (pin + 2))))) = 0XFF;
        }
        else
        {
            (*((volatile uint32*) (0x40025000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    }

}

uint8 GPIO_READ_PORT(GPIOPortID_t port)
{
    uint8 value = 0;
    switch (port)
    {
    case PA:
        value = PORTADAT;
        break;
    case PB:
        value = PORTBDAT;
        break;
    case PC:
        value = PORTCDAT;
        break;
    case PD:
        value = PORTDDAT;
        break;

    case PE:
        value = PORTEDAT;
        break;

    case PF:
        value = PORTFDAT;
        break;
    }

    return value;
}
uint8 GPIO_READ_PIN(GPIOPortID_t port, GPIOPinID_t pin)
{

    uint8 value = 0;

    switch (port)
    {
    case PA:
        value = GET_BIT(PORTADAT, pin);
        break;

    case PB:
        value = GET_BIT(PORTBDAT, pin);
        break;

    case PC:
        value = GET_BIT(PORTCDAT, pin);
        break;

    case PD:
        value = GET_BIT(PORTDDAT, pin);
        break;
    case PE:
        value = GET_BIT(PORTEDAT, pin);
        break;
    case PF:
        value = GET_BIT(PORTFDAT, pin);
        break;
    }

    return value;

}
