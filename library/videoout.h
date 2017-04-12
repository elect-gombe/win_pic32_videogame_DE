#ifdef __cplusplus
extern "C"{
#endif
  
// �R���|�W�b�g�J���[�M���o�̓v���O���� ���𑜓x��4�i������f�j�@PIC32MX150F128B�p�w�b�_�[�t�@�C���@by K.Tanaka
//�@4�r�b�g�P��VRAM�A16�F

#define X_RES	256 // �������𑜓x
#define Y_RES	224 // �c�����𑜓x
#define H_WORD	(X_RES/4) // 1�s����̃��[�h��(16bit�P��)

// ���̓{�^���̃|�[�g�A�r�b�g��`
#define KEYPORT PORTB
#define KEYUP 0x0400
#define KEYDOWN 0x0080
#define KEYLEFT 0x0100
#define KEYRIGHT 0x0200
#define KEYSTART 0x0800
#define KEYFIRE 0x4000

extern volatile char drawing;		//�@�\�����Ԓ���-1
extern volatile unsigned short drawcount;		//�@1��ʕ\���I�����Ƃ�1�����B�A�v������0�ɂ���B
							// �Œ�1��͉�ʕ\���������Ƃ̃`�F�b�N�ƁA�A�v���̏���������ʊ��ԕK�v���̊m�F�ɗ��p�B

extern unsigned short VRAM[];
extern unsigned short *volatile VRAMp; //������VRAM�A�h���X
  
#ifdef __cplusplus
}
#endif
  
namespace video{
  void start_composite(void); //�J���[�R���|�W�b�g�o�͊J�n
  void stop_composite(void); //�J���[�R���|�W�b�g�o�͒�~
  void init_composite(void); //�J���[�R���|�W�b�g�o�͏�����
  void clearscreen(void); //��ʃN���A
  void set_palette(unsigned char n,unsigned char b,unsigned char r,unsigned char g); //�J���[�p���b�g�ݒ�

  void clearscreen(void);
  //�O���t�B�b�N��ʃN���A
  void set_palette(unsigned char n,unsigned char b,unsigned char r,unsigned char g);
  //�O���t�B�b�N�p�J���[�p���b�g�ݒ�
 
  void pset(int x,int y,unsigned int c);
  // (x,y)�̈ʒu�ɃJ���[c�œ_��`��
 
  void putbmpmn(int x,int y,char m,char n,const unsigned char bmp[]);
  // ��m*�cn�h�b�g�̃L�����N�^�[�����Wx,y�ɕ\��
  // unsigned char bmp[m*n]�z��ɁA�P���ɃJ���[�ԍ�����ׂ�
  // �J���[�ԍ���0�̕����͓����F�Ƃ��Ĉ���
 
  void clrbmpmn(int x,int y,char m,char n);
  // �cm*��n�h�b�g�̃L�����N�^�[����
  // �J���[0�œh��Ԃ�
 
  void gline(int x1,int y1,int x2,int y2,unsigned int c);
  // (x1,y1)-(x2,y2)�ɃJ���[c�Ő�����`��
 
  void hline(int x1,int x2,int y,unsigned int c);
  // (x1,y)-(x2,y)�ւ̐������C���������`��
 
  void circle(int x0,int y0,unsigned int r,unsigned int c);
  // (x0,y0)�𒆐S�ɁA���ar�A�J���[c�̉~��`��
 
  void boxfill(int x1,int y1,int x2,int y2,unsigned int c);
  // (x1,y1),(x2,y2)��Ίp���Ƃ���J���[c�œh��ꂽ�����`��`��
 
  void circlefill(int x0,int y0,unsigned int r,unsigned int c);
  // (x0,y0)�𒆐S�ɁA���ar�A�J���[c�œh��ꂽ�~��`��
 
  void putfont(int x,int y,unsigned int c,int bc,unsigned char n);
  //8*8�h�b�g�̃A���t�@�x�b�g�t�H���g�\��
  //���W�ix,y)�A�J���[�ԍ�c
  //bc:�o�b�N�O�����h�J���[�A�����̏ꍇ����
  //n:�����ԍ�
 
  void printstr(int x,int y,unsigned int c,int bc,unsigned char *s);
  //���W(x,y)����J���[�ԍ�c�ŕ�����s��\���Abc:�o�b�N�O�����h�J���[
 
  void printnum(int x,int y,unsigned char c,int bc,unsigned int n);
  //���W(x,y)�ɃJ���[�ԍ�c�Ő��ln��\���Abc:�o�b�N�O�����h�J���[
 
  void printnum2(int x,int y,unsigned char c,int bc,unsigned int n,unsigned char e);
  //���W(x,y)�ɃJ���[�ԍ�c�Ő��ln��\���Abc:�o�b�N�O�����h�J���[�Ae���ŕ\��
 
  unsigned int getcolor(int x,int y);
  //���W(x,y)��VRAM��̌��݂̃p���b�g�ԍ���Ԃ��A��ʊO��0��Ԃ�

}

