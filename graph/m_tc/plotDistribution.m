%% Minutes
x_label =[1 2 3 4 5 6 7 8 9 10];



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.54127	0.51309	0.49544	0.48428	0.47292	0.46531	0.4588	0.45408	0.44815	0.44675];
%y_12 = [0.54948	0.5275	0.51155	0.50202	0.49508	0.48839	0.4814	0.48108	0.4783	0.47521];
%y_13 = [0.54948	0.5275	0.51155	0.50202	0.49508	0.48839	0.4814	0.48108	0.4783	0.47521];

%y_12 = [0.54971	0.5268	0.51393	0.50151	0.49969	0.4907	0.4889	0.48722	0.48099	0.47704];
%y_13 = [0.54971	0.5268	0.51393	0.50151	0.49969	0.4907	0.4889	0.48722	0.48099	0.47704];


%E[V_O]
%y_11 = [36.854575	49.012702	56.11301	61.293225	64.820715	68.431151	70.660003	72.762899	74.900038	76.261343];
%y_12 = [33.005249	41.982556	47.355761	50.89515	53.631171	56.260473	58.279415	59.588065	60.911769	61.66795];
%y_13 = [33.005249	41.982556	47.355761	50.89515	53.631171	56.260473	58.279415	59.588065	60.911769	61.66795];

%y_12 = [32.38983	41.517546	47.179295	51.106176	53.604574	56.333229	58.065054	59.105314	60.412114	62.042673];
%y_13 = [32.38983	41.517546	47.179295	51.106176	53.604574	56.333229	58.065054	59.105314	60.412114	62.042673];


%E[V_D]
y_11 = [172.597848	176.616982	179.33657	181.559901	182.89239	184.291941	185.272491	186.26368	187.058556	187.496538];
%y_12 = [170.77418	173.550009	175.675686	177.105396	178.124454	179.376397	180.220664	180.380797	180.890892	181.100519];
%y_13 = [170.77418	173.550009	175.675686	177.105396	178.124454	179.376397	180.220664	180.380797	180.890892	181.100519];

y_12 = [170.378091	173.73631	175.495709	177.439333	177.841315	179.182658	179.458333	179.958376	180.672068	181.523299]
y_13 = [170.378091	173.73631	175.495709	177.439333	177.841315	179.182658	179.458333	179.958376	180.672068	181.523299]



i = i+1;
figure(i)

sz = 80;
plot(x_label,y_11,'--', 'LineWidth',1.3)
%scatter(x_label,y_11,sz,'d','green', 'LineWidth',1.3)
hold on
plot(x_label,y_12,'-', 'LineWidth',1.3,'color','green')
%scatter(x_label,y_12,sz2,'s','red', 'LineWidth',1.3)
hold on
%plot(x_label,y_13,'-', 'LineWidth',1.3)
scatter(x_label,y_13,sz,'d','red', 'LineWidth',1.3)
hold on


%ylabel('P_{miss}')
%ylabel('Average Offloading Volume (MB)')
ylabel('Average Download Volume (MB)')
xlabel('E[T_C] (Unit: minutes)')


xticklabels({'1','2','3','4','5','6','7','8','9','10'});

												
xlim([1, 10]);


set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
%legend({'r_2=r_1 (Constant Bandwidth)','r_2=2r_1(Multiple Bandwidth)','r_2=3r_1(Multiple Bandwidth)','r_2=4r_1(Multiple Bandwidth)'},'NumColumns',1);
%legend({'Constant Bandwidth','Multiple Bandwidth (m=3)'},'NumColumns',1);

legend({'Sou model (Math.)','Proposed Model (Math.)','Proposed Model (Sim.)'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[T_C]'},'NumColumns',1);
%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2]=E[t_3])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[t_3]=E[T_C]'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth (m=2)','Multiple Bandwidth (m=3)'},'NumColumns',1);

hold off;
grid on;