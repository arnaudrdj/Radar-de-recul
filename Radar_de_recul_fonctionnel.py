import pyb
from machine import I2C
import VL53L0X
from time import sleep_ms

# Configuration des broches
buzzer_pin = pyb.Pin('D6', pyb.Pin.OUT_PP)  # Broche pour le buzzer
timer = pyb.Timer(1, freq=20000)  # Timer pour générer le signal PWM

# Configuration du capteur de distance
i2c = I2C(1)
tof = VL53L0X.VL53L0X(i2c)

# Fonction pour remapper un intervalle de valeurs dans un autre
def map_value(value, from_min, from_max, to_min, to_max):
    return (value - from_min) * (to_max - to_min) / (from_max - from_min) + to_min

# Définition des plages de distances et des durées de son correspondantes
distance_ranges = [(0, 150), (150, 400), (400, 600), (600, 800), (800, 1200), (1200, 1400), (1400, 1700)]
sound_durations = [5, 50, 100, 200, 400, 600, 800]

# Fonction pour sélectionner la durée de son en fonction de la distance mesurée
def get_sound_duration(distance):
    for i, (min_dist, max_dist) in enumerate(distance_ranges):
        if min_dist <= distance <= max_dist:
            return sound_durations[i]
    # Si la distance n'est dans aucune plage, retourne la dernière durée de son
    return sound_durations[-1]

# Fonction pour générer un son en fonction de la distance mesurée
def generate_sound(distance):
    # Définir une fréquence fixe pour le buzzer
    frequency = 10000  # Vous pouvez ajuster cette valeur pour obtenir le son désiré
    duration = get_sound_duration(distance)  # Obtenir la durée de son correspondante
    timer.freq(int(frequency))  # Définir la fréquence du timer
    buzzer_pin.high()  # Activer le buzzer
    sleep_ms(duration)  # Temps de son
    buzzer_pin.low()  # Désactiver le buzzer
    sleep_ms(duration)  # Temps de silence

# Fonction principale
def main():
    try:
        while True:
            # Mesure de la distance
            distance = min(max(tof.read(), 1), 1700)
            # Génération du son en fonction de la distance
            generate_sound(distance)
            # Affichage de la distance
            print("Distance:", distance, "mm")
            # Temporisation
            sleep_ms(100)
    except KeyboardInterrupt:
        print("Arrêt du programme.")

# Appel de la fonction principale
if __name__ == "__main__":
    main()
