#include<stdio.h>
#include<signal.h> 

int main() {
	#if 0
	char c;
	//getchar()��������Ϊint  

	while((c = getchar()) != EOF) {	//������ֿ���:һ�ǺϷ��������ַ��ڱ��ضϺ��ǵ�c��ȡֵ��EOF��ͬ
									//���ǲ�����ȡ��EOF���ֵ 
									//���������ƺ���������,����Ϊ�ɺ�,���ܷ���ֵ�ض�,
									//���ܱȽ��������������getchar�ķ���ֵ
		putchar(c);
	}
	#endif
	
	/*FILE *fp;
	fp = fopen(file, "r+");
	//��������ļ����ɱ���fileָ�����ļ�
	//Ϊ�˱������ȡ����ͬʱ���ж�д�����ĳ�������¼�����,һ����������������ֱ�ӽ���һ���������
	//���Ҫͬʱ����������������,���������в���fseek�����ĵ���ŷ�� 
	*/
	
	#if 0
	FILE *fp;
	struct record rec;
	
	while(fread((char *)&rec, sizeof(rec), 1, fp) == 1) {
		/*��recִ��ĳЩ����*/
		if(/*rec���뱻����д��*/) {
			fseek(fp, -(long)sizeof(rec), 1);
			fwrite((char *)&rec, sizeof(rec), 1, fp);
		} 
	}
	//&rec�ڴ���fread��fwrite����ʱ��С������ת��Ϊ�ַ�ָ������,sizeof(rec)��ת��Ϊ������
	//fseek����Ҫ��ڶ���������long��,��Ϊint���͵����������޷�����һ���ļ��Ĵ�С;sizeof����ʱunsignedֵ
	//������ȱ��뽫��ת��Ϊ�з������Ͳ��п��ܽ��䷴��
	//�ɸ�д:
	while(fread((char *)&rec, sizeof(rec), 1, fp) == 1) {
		/*��recִ��ĳЩ����*/
		if(/*rec���뱻����д��*/) {
			fseek(fp, -(long)sizeof(rec), 1);
			fwrite((char *)&rec, sizeof(rec), 1, fp);
			fseek(fp, 0L, 1);	//���ı����ļ���״̬,ʹ�ļ����ڿ����������ж�ȡ�� 
		} 
	} 
	#endif
	
	#if 0
	//������������ַ�ʽ:һ���Ǽ���ʱ����ʽ,��һ�������ݴ�����,Ȼ���ڴ��д��ķ�ʽ
	//ǰ��������ɽϸߵ�ϵͳ����,���,C����ʵ��ͨ���������Ա����ʵ�ʵ�д����֮ǰ���Ʋ��������������
	int c; 
	char buf[BUFSIZ];
	setbuf(stdout, buf); 
	/*��佫֪ͨ����/�����,����д�뵽stdout�������Ӧ��ʹ��buf��Ϊ���������,ֱ��buf���������������߳���Աֱ�ӵ���
	fflush(������д�����򿪵��ļ�,����fflush��������������������ݱ�ʵ��д����ļ�),buf�����������ݲ�ʵ��д�뵽
	stdout��.�������Ĵ�С��ϵͳͷ�ļ�<stdio.h>�е�BUFSIZ */
	
	while((c = getchar()) != EOF)
		putchar(c);
	//main��������֮��,buf�Ѿ����ͷ�
	//�Ľ���static char buf[BUFSIZ] ,Ҳ���Է���������
	//�ڶ��ַ���:
	char *malloc();
	setbuf(stdout, malloc(BUFSIZ));
	#endif
	
	#if 0
	//���ÿ⺯��ʱ,Ӧ�����ȼ����Ϊ����ָʾ�ķ���ֵ,ȷ������ִ���Ѿ�ʧ��,Ȼ���ڼ��errno,�����������ԭ��
	
	/*���ÿ⺯��*/
	if(���صĴ���ֵ) 
		���errno 
	#endif
	
	#if 0
	//�����첽�¼���һ�ַ�ʽ 
	signal(signal type, handler function);
	//signal type����ϵͳͷ�ļ�signal�ж����ĳЩ����������ʶsignal������Ҫ������ź�����
	//handler function�ǵ�ָ�����¼�����ʱ,��Ҫ���Ե��õ��¼�������
	//�ź��������ܳ�����ĳЩ���ӿ⺯��(��malloc)��ִ�й�����,��˴Ӱ�ȫ�ĽǶȿ���,�źŵĴ�������Ӧ�õ����������͵Ŀ⺯�� 
	#endif
	
	
	return 0;
}
