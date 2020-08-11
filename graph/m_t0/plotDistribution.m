%% Minutes
x_label =[1 2 3 4 5 6 7 8 9 10];



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.43694	0.46397	0.48332	0.49363	0.50814	0.51766	0.52466	0.5311 0.53914	0.54365];  %   sou model constant
%y_12 = [0.46327	0.48629	0.50458	0.51697	0.52702	0.53428	0.54158	0.54702 0.55357	0.5581]; % nutt model math 
%y_13 = [0.46327	0.48629	0.50458	0.51697	0.52702	0.53428	0.54158	0.54702 0.55357	0.5581]; %  nutt model sim

%y_12 = [0.46618	0.49262	0.5087	0.5166	0.52613	0.53592	0.5429	0.54768	0.55522	0.55814];
%y_13 = [0.46618	0.49262	0.5087	0.5166	0.52613	0.53592	0.5429	0.54768	0.55522	0.55814];



%E[V_O]
%y_11 = [79.790783	68.996878	61.406268	55.942602	50.969902 46.852809	43.626238	41.110291	38.416518	36.252686]; %   sou model constant
%y_12 = [66.7495	57.808782	50.509389	46.034537	41.981603 38.978738	35.824753	34.06753	31.780592	29.691121]; % nutt model math 
%y_13 = [66.7495	57.808782	50.509389	46.034537	41.981603 38.978738	35.824753	34.06753	31.780592	29.691121]; %  nutt model sim

%y_12 = [66.67651	56.923948	50.486703	46.272222	41.812891 38.575385	35.869174	33.741454	31.335161	29.765093];
%y_13 = [66.67651	56.923948	50.486703	46.272222	41.812891 38.575385	35.869174	33.741454	31.335161	29.765093];



%E[V_D]
y_11 = [188.505949	184.431085	181.455533	179.877735	177.641333	176.221484	174.696053	174.120647	173.016195	172.25369]; %   sou model constant
%y_12 = [183.053974	179.455131	176.936524	175.184423	173.918873 172.553849	171.610447	170.882335	169.768753	169.056509]; % nutt model math 
%y_13 = [183.053974	179.455131	176.936524	175.184423	173.918873 172.553849	171.610447	170.882335	169.768753	169.056509]; %  nutt model sim

y_12 = [182.792181	178.834689	176.425122	175.661389	173.988747 172.558522	171.379433	170.904389	169.860879	169.22702]
y_13 = [182.792181	178.834689	176.425122	175.661389	173.988747 172.558522	171.379433	170.904389	169.860879	169.22702]




i = i+1;
figure(i)
sz = 80;
%sz2 = 100;


plot(x_label,y_11,'--', 'LineWidth',1.3)
%scatter(x_label,y_11,sz,'d','green', 'LineWidth',1.3)
hold on
plot(x_label,y_12,'-', 'LineWidth',1.3,'color','green')
%scatter(x_label,y_12,sz2,'s','red', 'LineWidth',1.3)
hold on
%plot(x_label,y_13,'-', 'LineWidth',1.3)
scatter(x_label,y_13,sz,'d','red', 'LineWidth',1.3)
hold on

%plot(x_label,y_14,'--o', 'MarkerSize',8, 'LineWidth',1.3)
%hold on


%ylabel('P_{miss}')
%ylabel('Average Offloading Volume (MB)')
ylabel('Average Download Volume (MB)')
xlabel('E[T_0] (Unit: minutes)')


xticklabels({'1','2','3','4','5','6','7','8','9','10'});

												
xlim([1, 10]);


set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
%legend({'r_2=r_1 (Constant Bandwidth)','r_2=2r_1(Multiple Bandwidth)','r_2=3r_1(Multiple Bandwidth)','r_2=4r_1(Multiple Bandwidth)'},'NumColumns',1);
%legend({'Constant Bandwidth','Multiple Bandwidth (m=3)'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth(Settings 1)','Multiple Bandwidth(Settings 2)'},'NumColumns',1);
legend({'Sou model (Math.)','Proposed Model (Math.)','Proposed Model (Sim.)'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[T_C]'},'NumColumns',1);
%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2]=E[t_3])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[t_3]=E[T_C]'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth (m=2)','Multiple Bandwidth (m=3)'},'NumColumns',1);

hold off;
grid on;