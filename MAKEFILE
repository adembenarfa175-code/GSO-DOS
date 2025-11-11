# MAKEFILE الرئيسي لـ GSO-DOS

# ترتيب البناء الجديد: UEFI أولاً، ثم DOS والنظام الفرعي
SUBSYSTEMS = UEFI DOS CMD DEV MAPPER MESSAGES

all: $(SUBSYSTEMS)

UEFI:
cd UEFI && $(MAKE)

DOS:
cd DOS && $(MAKE)

CMD:
cd CMD && $(MAKE)

DEV:
cd DEV && $(MAKE)

MAPPER:
cd MAPPER && $(MAKE)

MESSAGES:
cd MESSAGES && $(MAKE)

clean:
for dir in $(SUBSYSTEMS); do \
(cd $$dir && $(MAKE) clean); \
done
