import serial
import pygame
pygame.init()
screen = pygame.display.set_mode([300,100])
screen.fill([255,255,255])
ser = serial.Serial("/dev/ttyUSB0", 9600)

flag = -1


while True:

    key = pygame.key.get_pressed()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                pygame.quit()
                break
        elif event.type == pygame.KEYDOWN:
            print("KEYDoWN")
            if event.key == pygame.K_w:
                ser.write(b'7')
                flag = 0
            if event.key == pygame.K_a:
                ser.write(b'1')
                flag = 0
            if event.key == pygame.K_s:
                ser.write(b'8')
                flag = 0
            if event.key == pygame.K_d:
                ser.write(b'3')
                flag = 0
            if event.key == pygame.K_k:
                ser.write(b'k')
                flag = 0
            if event.key == pygame.K_l:
                ser.write(b'l')
                flag = 0
            if event.key == pygame.K_z:
                ser.write(b'z')
                flag = 0
            if event.key == pygame.K_ESCAPE:
                flag = 0
                break
            if event.key == pygame.K_UP:
                ser.write(b'5')
                flag = 1
            if event.key == pygame.K_DOWN:
                ser.write(b'6')
                flag = 2
            
            if event.key == pygame.K_LEFT:
               ser.write(b'g')
            if event.key == pygame.K_RIGHT:
               ser.write(b'h')
            if event.key == pygame.K_c: ## Conveyor Belt
                ser.write(b'c')
            if event.key == pygame.K_v: ## Intake motor - Johnson
                ser.write(b'v')
            if event.key == pygame.K_q: ## Stop Everything
                ser.write(b'q')
        elif event.type == pygame.KEYUP:
            print("kEYUP")
            ser.write(b'0')
            flag = 0

#    if flag == 1:
#        ser.write(b'5')

#    elif flag == 2:
#        ser.write(b'6')
    
    pygame.display.update()
