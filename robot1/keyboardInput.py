import serial
import pygame
import pygame.camera
import sys

pygame.init()
pygame.camera.init()
screen = pygame.display.set_mode([640,480])
#cam = pygame.camera.Camera("/dev/video0",(640,480))
#cam.start()
##screen.fill([255,255,255])
ser = serial.Serial("/dev/ttyUSB0", 9600)

flag = -1


while True:
#    image = cam.get_image()
#    screen.blit(image, (0,0))
    key = pygame.key.get_pressed()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
                break
        elif event.type == pygame.KEYDOWN:
            print("KEYDoWN")
            if event.key == pygame.K_p: ## Shooting
                ser.write(b'1')
                flag = 0
            if event.key == pygame.K_c: ## Conveyor Belt Trigger
                ser.write(b'3')
                flag = 0
            if event.key == pygame.K_LEFT: ## Anti - CLockwise
                ser.write(b'8')
                flag = 0
            if event.key == pygame.K_RIGHT: ## Clockwise
                ser.write(b'7')
                flag = 0
            if event.key == pygame.K_UP:
                ser.write(b'5')
                flag = 1
            if event.key == pygame.K_DOWN:
                ser.write(b'6')
                flag = 2
            if event.key == pygame.K_q: ## Stop everything
                ser.write(b'q')
            if event.key == pygame.K_w:
                ser.write(b'w')
            if event.key == pygame.K_s:
                ser.write(b's')
            if event.key == pygame.K_a:
                ser.write(b'a')
            if event.key == pygame.K_d:
                ser.write(b'd')
            if event.key == pygame.K_ESCAPE:
                sys.exit()

        elif event.type == pygame.KEYUP:
            print("kEYUP")
            ser.write(b'0')
            flag = 0
       
    pygame.display.update()
