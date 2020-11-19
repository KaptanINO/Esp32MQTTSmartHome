# Esp32MQTTSmartHome

Esp 32 ile kullanabileceğiniz MQTT tabanlı akıllı ev sistemi.

PIN dizilimleri kodun içinde mevcuttur.

PIN	Durumu	  Notlar
0	pulled up	OK	Açılışta PWM sinyal verir.
1	TX pin	  OK	Başlangıçta Debug Pini.
2	OK	      OK	Karttaki Led'e bağlıdır.
3	OK	      RX Açılışta Sinyal Verir.
4	OK	      OK	
5	OK	      OK Açılışta PWM sinyal verir.
6	x	        x Dahili SPI Flash'a bağlı.
7	x	        x	Dahili SPI Flash'a bağlı.
8	x	        x	Dahili SPI Flash'a bağlı.
9	x	        x	Dahili SPI Flash'a bağlı.
10x	        x	Dahili SPI Flash'a bağlı.
11x         x	Dahili SPI Flash'a bağlı.
12	OK	    OK	Eğer pin'e güç verilirse başlatam başarısız olur.
13	OK	    OK	
14	OK	    OK	Açılışta PWM sinyal verir
15	OK	    OK	Açılışta PWM sinyal verir
16	OK	    OK	
17	OK	    OK	
18	OK	    OK	
19	OK		  OK	
21	OK		  OK	
22	OK		  OK	
23	OK		  OK	
25	OK		  OK	
26	OK		  OK	
27	OK			OK	
32	OK			OK	
33	OK			OK	
34	OK		  Sadece giriş sinyali
35	OK		  Sadece giriş sinyali
36	OK		  Sadece giriş sinyali
39	OK		  Sadece giriş sinyali

(OK=Kullanılabilir/X=Kullanılamaz)
